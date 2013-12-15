#ifndef MEDIATOR_GRIDABLE_WRITER_H
#define MEDIATOR_GRIDABLE_WRITER_H


#include "game.types.h"
#include "igridable.h"
#include "igamewriter.h"


class MediatorGridableToWriter
{
private:

  IGridable *_pboard;
  IGameWriter *_pwriter;


public:

  MediatorGridableToWriter(IGridable *pboard, IGameWriter *pwriter);

  void draw(void);
  void draw(int_pair origin, int_pair extent);

};


#endif  // MEDIATOR_GRIDABLE_WRITER_H
