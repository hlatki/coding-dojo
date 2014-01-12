#include "main.h"

char char_iterator::operator()(void) const
{ return _sequencer(_idx) - '0'; }


bool char_iterator::is_more(void) const
{ return _is_more; }


char_iterator char_iterator::next(void) const
{ return char_iterator(_sequencer, _idx-1, _end_idx); }


int char_iterator::to_i(void) const
{ return _idx; }


char_iterator sequence_iterator::operator()(void) const
{ return char_iterator(_sequencer, _idx, 0); }


bool sequence_iterator::is_more(void) const
{ return _is_more; }


sequence_iterator sequence_iterator::next(void) const
{ return sequence_iterator(_sequencer, _idx+1, _end_idx); }


int sequence_iterator::to_i(void) const
{ return _idx; }
