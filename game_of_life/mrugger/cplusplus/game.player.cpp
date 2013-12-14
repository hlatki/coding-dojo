#include <stdio.h>
#include <utility>
#include "game.player.h"


GamePlayer::GamePlayer(int_pair board_size,
                       int_pair pattern_position,
                       IGridable *pattern)
{
  _pboard_current = new GameBoard(board_size, pattern_position, pattern);
  _pboard_next = new GameBoard(_pboard_current);
}


void GamePlayer::next_generation(void)
{
  _pboard_next->next_generation(_pboard_current);
  std::swap(_pboard_current, _pboard_next);
}


// IGridable

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
