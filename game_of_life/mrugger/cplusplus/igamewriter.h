#ifndef IGAMEWRITER_H
#define IGAMEWRITER_H



enum CELL_TYPE
{
  CELL_DEAD = 0,
  CELL_ALIVE,
  CELL_ENDOF
};



class IGameWriter
{
public:

  virtual void begin_board(void) = 0;
  virtual void begin_row(void) = 0;
  virtual void write_cell(CELL_TYPE celltype) = 0;
  virtual void end_row(void) = 0;
  virtual void end_board(void) = 0;

};


#endif  // IGAMEWRITER_H
