#include <stdio.h>
#include "game-player.h"


GamePlayer::GamePlayer(int_point board_size,
                       int_point pattern_position,
                       IQueryableBoard *pattern)
{
  _pboard_current = new GameBoard(board_size.x, board_size.y,
                                  pattern_position.x, pattern_position.y,
                                  pattern);

  _pboard_next = new GameBoard(_pboard_current);
}


GamePlayer::GamePlayer(int x_width, int y_width,
                     int pattern_x_position, int pattern_y_position,
                     IQueryableBoard *pattern)
{
  _pboard_current = new GameBoard(x_width, y_width,
                                  pattern_x_position, pattern_y_position,
                                  pattern);

  _pboard_next = new GameBoard(_pboard_current);
}


void GamePlayer::next_generation(void)
{
  _pboard_next->next_generation(_pboard_current);

  GameBoard *ptemp = _pboard_current;
  _pboard_current = _pboard_next;
  _pboard_next = ptemp;
}


// IQueryableBoard

int GamePlayer::get_width(void)
{
  return _pboard_current->get_width();
}


int GamePlayer::get_height(void)
{
  return _pboard_current->get_height();
}


CELL_TYPE GamePlayer::node_value(int x, int y)
{
  return _pboard_current->node_value(x, y);
}
