#ifndef GAMEPLAYER_H
#define GAMEPLAYER_H


#include "game.board.h"
#include "igridable.h"


class GamePlayer : public IGridable
{
private:

  GameBoard *_pboard_current;
  GameBoard *_pboard_next;


public:

  GamePlayer(int_pair board_size);
  GamePlayer(int_pair board_size,
             int_pair pattern_position,
             IGridable *pattern);

  void add_pattern(int_pair position, IGridable *pattern, bool btransparent);
  void next_generation(void);


public:   // IGridable

  virtual int get_width(void);
  virtual int get_height(void);

  virtual CELL_TYPE node_value(int x, int y);

};


#endif  // GAMEPLAYER_H
