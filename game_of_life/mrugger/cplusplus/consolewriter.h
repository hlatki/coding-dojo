#ifndef CONSOLEWRITER_H
#define CONSOLEWRITER_H

#include "igamewriter.h"


class ConsoleWriter : public IGameWriter
{
public:

  static IGameWriter *create(void);


private: // IGameWriter

  virtual void begin_board(void);
  virtual void begin_row(void);
  virtual void write_cell(CELL_TYPE celltype);
  virtual void end_row(void);
  virtual void end_board(void);


private:

  ConsoleWriter(void);

};


#endif  // CONSOLEWRITER_H
