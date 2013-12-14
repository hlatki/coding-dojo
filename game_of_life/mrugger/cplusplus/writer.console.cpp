#include <stdio.h>
#include "writer.console.h"
#include "map.char_cell.h"


IGameWriter *WriterConsole::create(void)
{
  return new WriterConsole();
}


WriterConsole::WriterConsole(void)
{
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
}


void WriterConsole::write_cell(CELL_TYPE cell)
{
  printf("%c", MapCharCell::cell_to_char(cell));
}


void WriterConsole::end_row(void)
{
  _bnewline = true;
}


void WriterConsole::end_board(void)
{
}
