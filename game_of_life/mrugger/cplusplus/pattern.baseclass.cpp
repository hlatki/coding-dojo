#include <stdio.h>
#include <stdexcept>
#include "pattern.baseclass.h"


PatternBaseclass::PatternBaseclass(void)
{
}


PatternBaseclass::PatternBaseclass(int_pair pattern_size, const char *pattern[])
{
  initialize(pattern_size, pattern);
}


void PatternBaseclass::initialize(int_pair pattern_size, const char **pattern)
{
  _pattern_size = pattern_size;
  _pattern.reset(new CELL_TYPE[_pattern_size.x * _pattern_size.y]);

  for (int x = 0; x < _pattern_size.x; x++)
    for (int y = 0; y < _pattern_size.y; y++)
      node(x, y) = pattern[x][y] == CHARCELL_ALIVE ? CELL_ALIVE : CELL_DEAD;
}


CELL_TYPE &PatternBaseclass::node(int x, int y)
{
  if (x < 0 || x >= _pattern_size.x || y < 0 || y >= _pattern_size.y)
    throw std::invalid_argument("PatternBaseclass::node: Index out of range");

  return _pattern.get()[_pattern_size.x * y + x];
}


// IGridable

int PatternBaseclass::get_width(void)
{
  return _pattern_size.x;
}


int PatternBaseclass::get_height(void)
{
  return _pattern_size.y;
}


CELL_TYPE PatternBaseclass::node_value(int x, int y)
{
  if (x < 0 || x >= _pattern_size.x || y < 0 || y >= _pattern_size.y)
  {
    printf("\nx = %d, y = %d\n", x, y);
    throw std::invalid_argument("PatternBaseclass::node_value: Index out of range.");
  }

  return _pattern.get()[_pattern_size.x * y + x];
}
