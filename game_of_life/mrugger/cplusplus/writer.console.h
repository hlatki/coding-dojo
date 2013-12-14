#ifndef WRITER_CONSOLE_H
#define WRITER_CONSOLE_H

#include "igamewriter.h"


class WriterConsole : public IGameWriter
{
private:

  bool _bnewline;

  
public:

  static IGameWriter *create(void);


private: // IGameWriter

  virtual void begin_board(void);
  virtual void begin_row(void);
  virtual void write_cell(CELL_TYPE celltype);
  virtual void end_row(void);
  virtual void end_board(void);


private:

  WriterConsole(void);

};


#endif  // WRITER_CONSOLE_H