#ifndef IGRIDABLE_H
#define IGRIDABLE_H


#include "game.types.h"


class IGridable
{
public:

  virtual int get_width(void) = 0;
  virtual int get_height(void) = 0;

  virtual CELL_TYPE node_value(int x, int y) = 0;
  
};


#endif  // IGRIDABLE_H
