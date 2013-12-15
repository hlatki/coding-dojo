#include <stdio.h>
#include "writer.console.h"
#include "map.char-cell.h"


IGameWriter *WriterConsole::create(int_pair extent)
{
  return new WriterConsole(extent);
}


WriterConsole::WriterConsole(int_pair extent)
{
  _extent = extent;
  _pbuffer.reset(new char[extent.y + 1]);
  _pbuffer.get()[extent.y] = '\0';
  _buffer_position = 0;
  _bnewline = false;
}


void WriterConsole::begin_board(void)
{
  //printf("\033[H\033[J");
  printf("\033[H");
}


void WriterConsole::begin_row(void)
{
  if (_bnewline)
  {
    printf("\n");
    _bnewline = false;
  }

  _buffer_position = 0;
}


void WriterConsole::write_cell(CELL_TYPE cell)
{
  if (_buffer_position < _extent.y)
  {
    _pbuffer.get()[_buffer_position++] = MapCharCell::cell_to_char(cell);
  }
}


void WriterConsole::end_row(void)
{
  printf("%s", _pbuffer.get());
  _bnewline = true;
}


void WriterConsole::end_board(void)
{
}
