#include <iostream>
#include <string>
#include <list>
#include <ctime>
#include <chrono>
#include <iterator>
#include <algorithm>
#include "thread.h"
#include "sequencer.h"


static const accumulator process_sequence(const accumulator &acc, const sequencer &seq, const int depth);


static int match_count(const int count, const char_iterator &char_it, const char val)
{
  const char new_val = val - char_it();
  if (new_val > 0 && char_it.is_more())
    return match_count(count+1, char_it.next(), new_val);
  else if (new_val == 0)
    return count+1;
  else
    return 0;
}


static const accumulator on_each(const accumulator &acc, const char_iterator &char_it)
{
  if (char_it.is_more())
  {
    const int cnt = match_count(1, char_it.next(), char_it());
    if (cnt) return acc.append(match_pair(char_it.to_i(), cnt));
  }
  return acc;
}


static const accumulator iterate_sequence(const accumulator &acc, const sequencer &seq)
{
  sequence_iterator seq_it = seq.get_sequence_iterator();
  return seq_it.foreach<accumulator>(acc, on_each);
}


static const accumulator fork_sequence(const accumulator &acc, const sequencer &seq, const int depth)
{
  sequencer seq_front = seq.clone_front_half();
  mythread t(process_sequence, acc, seq_front, depth+1);

  sequencer seq_back = seq.clone_back_half();
  accumulator back_acc = process_sequence(accumulator(), seq_back, depth+1);

  return t.join().append(back_acc);
}


static const accumulator process_sequence(const accumulator &acc, const sequencer &seq, const int depth)
{
  if (seq.length() > 1024)
    return fork_sequence(acc, seq, depth);
  else
    return iterate_sequence(acc, seq);
}


static void print_list(const accumulator &acc, const sequencer &seq)
{
  const match_pair_vector &list = acc.get_vector();
  std::time_t tt = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
  std::cout << "Application done: " << ctime(&tt);
  std::cout << "list size: " << list.size() << std::endl;
  int number_of_line_items = std::min(10, (int) list.size());

  std::for_each(list.begin(), std::next(list.begin(), number_of_line_items), [seq](match_pair p)
  {
    const sequencer block = seq.clone_block(p.first-p.second+1, p.second);
    printf("Position: %3d, characters: %d, %s\n", p.first, p.second, block.to_s().c_str());
  });
}


int main(void)
{
  mythread::set_max_tree_depth();
  const int replications = 1000000;
  std::string str("8745648184845171326578518184151512461752149647129746915414816354846454");

  sequencer seq(str, replications);
  const accumulator acc = process_sequence(accumulator(), seq, 0);

  print_list(acc, seq);
  return 0;
}
