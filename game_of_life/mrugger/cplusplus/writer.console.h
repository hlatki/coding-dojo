#ifndef WRITER_CONSOLE_H
#define WRITER_CONSOLE_H


#include <memory>
#include "igamewriter.h"


class WriterConsole : public IGameWriter
{
private:

  int row;
  bool _bnewline;
  int_pair _extent;

  
public:

  static IGameWriter *create(void);
  static int_pair get_window_size(void);


private: // IGameWriter

  virtual int_pair begin_board(void);
  virtual void begin_row(void);
  virtual void write_cell(CELL_TYPE celltype);
  virtual void end_row(void);
  virtual void end_board(void);


private:

  WriterConsole(void);

};


#endif  // WRITER_CONSOLE_H
