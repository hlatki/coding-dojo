#include <stdio.h>
#include "consolewriter.h"


IGameWriter *ConsoleWriter::create(void)
{
  return new ConsoleWriter();
}


ConsoleWriter::ConsoleWriter(void)
{
  _bnewline = false;
}


void ConsoleWriter::begin_board(void)
{
  //printf("\033[H\033[J");
  printf("\033[H");
}


void ConsoleWriter::begin_row(void)
{
  if (_bnewline)
  {
    printf("\n");
    _bnewline = false;
  }
}


void ConsoleWriter::write_cell(CELL_TYPE celltype)
{
  printf("%c", celltype ? '*' : ' ');
}


void ConsoleWriter::end_row(void)
{
  _bnewline = true;
}


void ConsoleWriter::end_board(void)
{
}
