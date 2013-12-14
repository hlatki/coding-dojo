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

  GamePlayer(int_point board_size,
             int_point pattern_position,
             IQueryableBoard *pattern);

  GamePlayer(int x_width, int y_width,
            int pattern_x_position, int pattern_y_position,
            IQueryableBoard *pattern);

  void next_generation(void);


public:   // IQueryableBoard

  virtual int get_width(void);
  virtual int get_height(void);

  virtual CELL_TYPE node_value(int x, int y);

};


#endif  // GAMEPLAYER_H
