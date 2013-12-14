#ifndef GAMEBOARD_h
#define GAMEBOARD_h

#include "igridable.h"
#include "igamewriter.h"
#include "pattern.baseclass.h"
#include "game.grid.h"


class GameBoard : public GameGrid
{
public:


  GameBoard(IGridable *original);
  GameBoard(int_pair board_size,
            int_pair pattern_position,
            IGridable *pattern);


public:   // IGameBoard

  virtual void next_generation(IGridable *parent);


private:

  CELL_TYPE calculate_cell(IGridable *parent, int x, int y);
  int is_alive(IGridable *parent, int x, int y);

};


#endif  // GAMEBOARD_H
