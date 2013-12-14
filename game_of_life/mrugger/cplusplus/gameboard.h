#ifndef GAMEBOARD_h
#define GAMEBOARD_h

#include "iqueryableboard.h"
#include "igamewriter.h"
#include "pattern.baseclass.h"


class GameBoard : public IQueryableBoard
{
private:

  int GRID_SIZE_X;
  int GRID_SIZE_Y;

  CELL_TYPE *_board;


public:


  GameBoard(GameBoard *partner);
  GameBoard(int_pair board_size,
            int_pair pattern_position,
            IQueryableBoard *pattern);


public:   // IGameBoard

  virtual void next_generation(GameBoard *parent);


public:   // IQueryableBoard

  virtual int get_width(void);
  virtual int get_height(void);

  virtual CELL_TYPE node_value(int x, int y);


private:

  CELL_TYPE &node(int x, int y);
  CELL_TYPE calculate_cell(GameBoard *parent, int x, int y);
  int is_alive(GameBoard *parent, int x, int y);

};


#endif  // GAMEBOARD_H
