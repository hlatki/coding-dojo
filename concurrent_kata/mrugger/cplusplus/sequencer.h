#pragma once
#include <string>
#include <memory>
#include "iterators.h"


class sequencer
{
private:

  const std::shared_ptr<char> _sequence;
  const std::size_t _sequence_length;

  const int _start_idx;
  const int _end_idx;

public:

  sequencer(const std::string sequence, unsigned int replication_count);

  char operator()(int idx) const;

  sequence_iterator get_sequence_iterator(void) const;
  sequencer clone_front_half(void) const;
  sequencer clone_back_half() const;
  sequencer clone_block(int start, int length) const;
  int length(void) const;

  std::string to_s(void) const;


private:

  sequencer(const sequencer &other, int start, int end);

  void append_to_string(std::string &s, int idx, int count) const;

};
