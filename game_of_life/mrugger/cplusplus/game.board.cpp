#include <stdio.h>
#include <stdlib.h>
#include <stdexcept>
#include "game.board.h"


GameBoard::GameBoard(IGridable *original)
: GameGrid(original)
{
}


GameBoard::GameBoard(int_pair board_size,
                     int_pair pattern_position,
                     IGridable *pattern)
: GameGrid(board_size)
{
  for (int x = 0; x < pattern->get_width(); x++)
    for (int y = 0; y < pattern->get_height(); y++)
      node(pattern_position.x + x, pattern_position.y + y) = pattern->node_value(x, y);
}


void GameBoard::next_generation(IGridable *parent)
{
  for (int x = 0; x < get_width(); x++)
  {
    for (int y = 0; y < get_height(); y++)
    {
      node(x, y) = calculate_cell(parent, x, y);
    }
  }
}


CELL_TYPE GameBoard::calculate_cell(IGridable *parent, int x, int y)
{
  int living_cell_count;

  living_cell_count  = is_alive(parent, x-1, y-1);
  living_cell_count += is_alive(parent, x-1, y);
  living_cell_count += is_alive(parent, x-1, y+1);
  living_cell_count += is_alive(parent, x,   y-1);
  living_cell_count += is_alive(parent, x,   y+1);
  living_cell_count += is_alive(parent, x+1, y-1);
  living_cell_count += is_alive(parent, x+1, y);
  living_cell_count += is_alive(parent, x+1, y+1);

  if (living_cell_count < 2 || living_cell_count > 3)
    return CELL_DEAD;
  else if (parent->node_value(x, y) == CELL_ALIVE)
    return CELL_ALIVE;
  else if (living_cell_count == 3)
    return CELL_ALIVE;
  else
    return CELL_DEAD;
}


int GameBoard::is_alive(IGridable *parent, int x, int y)
{
  if (x < 0 || x >= parent->get_width() || y < 0 || y >= parent->get_height())
    return 0;

  return parent->node_value(x, y);
}
