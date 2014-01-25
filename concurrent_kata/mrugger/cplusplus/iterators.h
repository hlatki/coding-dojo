#pragma once
#include <list>
#include <functional>
#include <vector>

class sequencer;
class mutable_match_pair_accumulator;
class immutable_shared_match_pair_accumulator;
class immutable_byvalue_match_pair_accumulator;


typedef std::pair<int, int> match_pair;
typedef std::vector<match_pair> match_pair_vector;
typedef immutable_shared_match_pair_accumulator accumulator;


class char_iterator
{
private:

  const sequencer &_sequencer;
  const int _idx;
  const int _end_idx;
  const bool _is_more;

public:

  char_iterator(const sequencer &seq, int idx, int end_idx)
  : _sequencer(seq), _idx(idx), _end_idx(end_idx), _is_more(_idx > _end_idx)
  {}

//  char_iterator(const char_iterator &other)
//  : _sequencer(other._sequencer), _idx(other._idx), _end_idx(other._end_idx), _is_more(_idx > _end_idx)
//  {}

  char operator()(void) const;
  bool is_more(void) const;
  char_iterator next(void) const;
  int to_i(void) const;

};


class sequence_iterator
{
private:

  const sequencer &_sequencer;
  const int _idx;
  const int _end_idx;
  const bool _is_more;

public:

  sequence_iterator(const sequencer &seq, int idx, int end_idx)
  : _sequencer(seq), _idx(idx), _end_idx(end_idx), _is_more(_idx < _end_idx)
  {}


  char_iterator operator()(void) const;
  bool is_more(void) const;
  sequence_iterator next(void) const;
  int to_i(void) const;

  template <typename T>
  const T foreach(const T &acc, const std::function<const T(const T &, const char_iterator &)> fn)
  {
    if (is_more())
      return next().foreach(fn(acc, (*this)()), fn);
    else
      return fn(acc, (*this)());
  }

};
