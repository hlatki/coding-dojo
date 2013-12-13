#ifndef QUERYABLETOWRITER_H
#define QUERYABLETOWRITER_H


#include "iqueryableboard.h"
#include "igamewriter.h"


class QueryableToWriter
{
private:

  IQueryableBoard *_pboard;
  IGameWriter *_pwriter;


public:

  QueryableToWriter(IQueryableBoard *pboard, IGameWriter *pwriter);

  void draw(void);

};


#endif  // QUERYABLETOWRITER_H
