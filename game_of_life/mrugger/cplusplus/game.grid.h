#ifndef GAME_GRID_H
#define GAME_GRID_H


#include <memory>
#include "game.types.h"
#include "igridable.h"


class GameGrid : public IGridable
{
private:

  int_pair _grid_size;
  std::auto_ptr<CELL_TYPE> _grid;


protected:

  GameGrid(void);
  GameGrid(int_pair grid_size);
  GameGrid(IGridable *pattern);
  GameGrid(int_pair grid_size, const char **pattern);

  void initialize(IGridable *pattern);
  void initialize(int_pair grid_size, const char **pattern);
  CELL_TYPE &node(int x, int y);


public:  // IGridable

  virtual int get_width(void);
  virtual int get_height(void);

  virtual CELL_TYPE node_value(int x, int y);

};


#endif  // GAME_GRID_H
