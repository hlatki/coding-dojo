#ifndef IQUERYABLEBOARD_H
#define IQUERYABLEBOARD_H


#include "igamewriter.h"


class IQueryableBoard
{
public:

  virtual int get_width(void) = 0;
  virtual int get_height(void) = 0;

  virtual CELL_TYPE node_value(int x, int y) = 0;
  
};


#endif  // IQUERYABLEBOARD_H
