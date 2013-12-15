#include <sys/ioctl.h>
#include <cstdio>
#include <unistd.h>
#include <stdlib.h>
#include <stdexcept>
#include "writer.console.h"
#include "map.char-cell.h"


IGameWriter *WriterConsole::create(void)
{
  return new WriterConsole();
}


int_pair WriterConsole::get_window_size(void)
{
  struct winsize w;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
  int_pair rv = { w.ws_row - 1, w.ws_col };
  return rv;
}


WriterConsole::WriterConsole(void)
: _extent(get_window_size())
{
  _buffer_size = _extent.x * (_extent.y + 1);
  _pbuffer.reset(new char[_buffer_size + 1]);
  _pbuffer.get()[_buffer_size] = '\0';
  _buffer_position = 0;
  _bnewline = false;
}


int_pair WriterConsole::begin_board(void)
{
  //printf("\033[H\033[J");
  printf("\033[H");
  _buffer_position = 0;
  return _extent;
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
