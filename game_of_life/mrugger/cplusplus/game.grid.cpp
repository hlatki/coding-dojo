#include <stdio.h>
#include <stdexcept>
#include "game.grid.h"
#include "map.char-cell.h"


GameGrid::GameGrid(void)
{
}


GameGrid::GameGrid(int_pair grid_size)
{
  _grid_size = grid_size;
  int number_of_cells = _grid_size.x * _grid_size.y;

  _grid.reset(new CELL_TYPE[number_of_cells]);

  for (int a = 0; a < number_of_cells; a++)
    _grid.get()[a] = CELL_DEAD;
}


GameGrid::GameGrid(IGridable *pattern)
{
  initialize(pattern);
}


GameGrid::GameGrid(int_pair grid_size, const char *pattern[])
{
  initialize(grid_size, pattern);
}


void GameGrid::initialize(IGridable *pattern)
{
  _grid_size.x = pattern->get_width();
  _grid_size.y = pattern->get_height();
  int number_of_cells = _grid_size.x * _grid_size.y;

  _grid.reset(new CELL_TYPE[number_of_cells]);

  for (int x = 0; x < _grid_size.x; x++)
    for (int y = 0; y < _grid_size.y; y++)
      node(x, y) = pattern->node_value(x, y);
}


void GameGrid::initialize(int_pair grid_size, const char **pattern)
{
  _grid_size = grid_size;
  _grid.reset(new CELL_TYPE[_grid_size.x * _grid_size.y]);

  for (int x = 0; x < _grid_size.x; x++)
    for (int y = 0; y < _grid_size.y; y++)
      node(x, y) = MapCharCell::char_to_cell(pattern[x][y]);
}


CELL_TYPE &GameGrid::node(int x, int y)
{
  if (x < 0 || x >= _grid_size.x || y < 0 || y >= _grid_size.y)
    throw std::invalid_argument("GameGrid::node: Index out of range");

  return _grid.get()[_grid_size.x * y + x];
}


bool GameGrid::is_valid_position(int x, int y)
{
  return x >= 0 && x < _grid_size.x && y >= 0 && y < _grid_size.y;
}


// IGridable

int GameGrid::get_width(void)
{
  return _grid_size.x;
}


int GameGrid::get_height(void)
{
  return _grid_size.y;
}


CELL_TYPE GameGrid::node_value(int x, int y)
{
  if (x < 0 || x >= _grid_size.x || y < 0 || y >= _grid_size.y)
  {
    printf("\nx = %d, y = %d\n", x, y);
    throw std::invalid_argument("GameGrid::node_value: Index out of range.");
  }

  return _grid.get()[_grid_size.x * y + x];
}
