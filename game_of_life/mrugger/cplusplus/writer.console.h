#ifndef WRITER_CONSOLE_H
#define WRITER_CONSOLE_H


#include <memory>
#include "igamewriter.h"


class WriterConsole : public IGameWriter
{
private:

  int_pair _extent;
  std::auto_ptr<char> _pbuffer;
  int _buffer_size;
  int _buffer_position;
  bool _bnewline;

  
public:

  static IGameWriter *create(int_pair extent);


private: // IGameWriter

  virtual void begin_board(void);
  virtual void begin_row(void);
  virtual void write_cell(CELL_TYPE celltype);
  virtual void end_row(void);
  virtual void end_board(void);


private:

  WriterConsole(int_pair extent);

};


#endif  // WRITER_CONSOLE_H
