#ifndef QUERYABLETOWRITER_H
#define QUERYABLETOWRITER_H


#include "igridable.h"
#include "igamewriter.h"


class QueryableToWriter
{
private:

  IGridable *_pboard;
  IGameWriter *_pwriter;


public:

  QueryableToWriter(IGridable *pboard, IGameWriter *pwriter);

  void draw(void);

};


#endif  // QUERYABLETOWRITER_H
