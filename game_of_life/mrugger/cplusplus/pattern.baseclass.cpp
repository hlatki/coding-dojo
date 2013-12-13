#include <stdio.h>
#include <stdexcept>
#include "pattern.baseclass.h"


PatternBaseclass::PatternBaseclass(int x_size, int y_size, char **pattern)
{
  _x_size = x_size;
  _y_size = y_size;
  _pattern = pattern;
}


// IQueryableBoard

int PatternBaseclass::get_width(void)
{
  return _x_size;
}


int PatternBaseclass::get_height(void)
{
  return _y_size;
}


CELL_TYPE PatternBaseclass::node_value(int x, int y)
{
  if (x < 0 || x >= _x_size || y < 0 || y >= _y_size)
    throw std::invalid_argument("Index out of range.");

  return _pattern[x][y] == '*' ? CELL_ALIVE : CELL_DEAD;
}
