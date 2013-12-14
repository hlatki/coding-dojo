#ifndef GAMEPLAYER_H
#define GAMEPLAYER_H


#include "gameboard.h"
#include "iqueryableboard.h"


class GamePlayer : public IQueryableBoard
{
private:

  GameBoard *_pboard_current;
  GameBoard *_pboard_next;


public:

  GamePlayer(int_pair board_size,
             int_pair pattern_position,
             IQueryableBoard *pattern);

  void next_generation(void);


public:   // IQueryableBoard

  virtual int get_width(void);
  virtual int get_height(void);

  virtual CELL_TYPE node_value(int x, int y);

};


#endif  // GAMEPLAYER_H
