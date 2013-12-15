#ifndef IGAMEWRITER_H
#define IGAMEWRITER_H


#include "game.types.h"



class IGameWriter
{
public:

  virtual int_pair begin_board(void) = 0;
  virtual void begin_row(void) = 0;
  virtual void write_cell(CELL_TYPE celltype) = 0;
  virtual void end_row(void) = 0;
  virtual void end_board(void) = 0;

};


#endif  // IGAMEWRITER_H
