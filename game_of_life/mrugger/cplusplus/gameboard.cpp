#include <stdio.h>
#include <stdlib.h>
#include "gameboard.h"


GameBoard::GameBoard(GameBoard *partner)
{
  GRID_SIZE_X = partner->GRID_SIZE_X;
  GRID_SIZE_Y = partner->GRID_SIZE_Y;
  _board = new CELL_TYPE[GRID_SIZE_X*GRID_SIZE_Y];
}


GameBoard::GameBoard(int_pair board_size,
                     int_pair pattern_position,
                     IQueryableBoard *pattern)
{
  GRID_SIZE_X = board_size.x;
  GRID_SIZE_Y = board_size.y;
  _board = new CELL_TYPE[GRID_SIZE_X*GRID_SIZE_Y];

  for (int x = 0; x < GRID_SIZE_X * GRID_SIZE_Y; x++)
    _board[x] = CELL_DEAD;

  for (int x = 0; x < pattern->get_width(); x++)
    for (int y = 0; y < pattern->get_height(); y++)
      node(pattern_position.x + x, pattern_position.y + y) = pattern->node_value(x, y);
}


void GameBoard::next_generation(GameBoard *parent)
{
  for (int x = 0; x < GRID_SIZE_X; x++)
  {
    for (int y = 0; y < GRID_SIZE_Y; y++)
    {
      node(x, y) = calculate_cell(parent, x, y);
    }
  }
}


// IQueryableBoard

int GameBoard::get_width(void)
{
  return GRID_SIZE_X;
}


int GameBoard::get_height(void)
{
  return GRID_SIZE_Y;
}


CELL_TYPE GameBoard::node_value(int x, int y)
{
  return node(x, y);
}


CELL_TYPE &GameBoard::node(int x, int y)
{
  if (x < 0 || x >= GRID_SIZE_X || y < 0 || y >= GRID_SIZE_Y)
  {
    printf("Index out of range.\n");
    exit(1);
  }

  return _board[GRID_SIZE_X * y + x];
}


CELL_TYPE GameBoard::calculate_cell(GameBoard *parent, int x, int y)
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
  else if (parent->node(x, y) == CELL_ALIVE)
    return CELL_ALIVE;
  else if (living_cell_count == 3)
    return CELL_ALIVE;
  else
    return CELL_DEAD;
}


int GameBoard::is_alive(GameBoard *parent, int x, int y)
{
  if (x < 0 || x >= GRID_SIZE_X || y < 0 || y >= GRID_SIZE_Y)
    return 0;

  return parent->node(x, y);
}
