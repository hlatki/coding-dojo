#include <cstdio>
#include <stdlib.h>
#include <stdexcept>
#include <curses.h>
#include "writer.console.h"
#include "map.char-cell.h"


IGameWriter *WriterConsole::create(void)
{
  return new WriterConsole();
}


int_pair WriterConsole::get_window_size(void)
{
  int x, y;
  getmaxyx(stdscr, x, y);
  int_pair rv = { x, y };
  return rv;
}


WriterConsole::WriterConsole(void)
: _extent(get_window_size())
{
  _bnewline = false;
}


int_pair WriterConsole::begin_board(void)
{
  move(0, 0);
  row = 0;
  _bnewline = false;
  return _extent;
}


void WriterConsole::begin_row(void)
{
  if (_bnewline)
  {
    move(++row, 0);
    _bnewline = false;
  }
}


void WriterConsole::write_cell(CELL_TYPE cell)
{
  addch(MapCharCell::cell_to_char(cell));
}


void WriterConsole::end_row(void)
{
  _bnewline = true;
}


void WriterConsole::end_board(void)
{
  refresh();
}
