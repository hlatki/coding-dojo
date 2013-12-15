#include <stdio.h>
#include <stdexcept>
#include "writer.console.h"
#include "map.char-cell.h"


IGameWriter *WriterConsole::create(int_pair extent)
{
  return new WriterConsole(extent);
}


WriterConsole::WriterConsole(int_pair extent)
{
  _extent = extent;
  _buffer_size = extent.x * (extent.y + 1);
  _pbuffer.reset(new char[_buffer_size + 1]);
  _pbuffer.get()[_buffer_size] = '\0';
  _buffer_position = 0;
  _bnewline = false;
}


void WriterConsole::begin_board(void)
{
  //printf("\033[H\033[J");
  printf("\033[H");
  _buffer_position = 0;
}


void WriterConsole::begin_row(void)
{
  if (_bnewline)
  {
    _pbuffer.get()[_buffer_position++] = '\n';
    _bnewline = false;
  }
}


void WriterConsole::write_cell(CELL_TYPE cell)
{
  if (_buffer_position < _buffer_size)
  {
    _pbuffer.get()[_buffer_position++] = MapCharCell::cell_to_char(cell);
  }
  else
  {
    throw std::out_of_range("WriterConsole::write_cell: buffer_position exceeds buffer length");
  }
}


void WriterConsole::end_row(void)
{
  _bnewline = true;
}


void WriterConsole::end_board(void)
{
  printf("%s", _pbuffer.get());
}
