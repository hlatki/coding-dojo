#include <stdio.h>
#include "consolewriter.h"


IGameWriter *ConsoleWriter::create(void)
{
  return new ConsoleWriter();
}


ConsoleWriter::ConsoleWriter(void)
{
}


void ConsoleWriter::begin_board(void)
{
  //printf("\033[H\033[J");
  printf("\033[H");
}


void ConsoleWriter::begin_row(void)
{
  printf("\n");
}


void ConsoleWriter::write_cell(CELL_TYPE celltype)
{
  printf("%c", celltype ? '*' : ' ');
}


void ConsoleWriter::end_row(void)
{
}


void ConsoleWriter::end_board(void)
{
}
