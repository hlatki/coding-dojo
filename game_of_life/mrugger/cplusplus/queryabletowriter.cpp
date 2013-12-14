#include <stdio.h>
#include <stdexcept>
#include "queryabletowriter.h"


QueryableToWriter::QueryableToWriter(IGridable *pboard, IGameWriter *pwriter)
{
  if (pboard == NULL)
    throw std::invalid_argument("pboard is null");

  if (pwriter == NULL)
    throw std::invalid_argument("pwriter is null");

  _pboard = pboard;
  _pwriter = pwriter;
}


void QueryableToWriter::draw(void)
{
  _pwriter->begin_board();
  for (int x = 0; x < _pboard->get_width(); x++)
  {
    _pwriter->begin_row();
    for (int y = 0; y < _pboard->get_height(); y++)
    {
      _pwriter->write_cell(_pboard->node_value(x, y));
    }
    _pwriter->end_row();
  }
  _pwriter->end_board();
}
