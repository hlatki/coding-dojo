#ifndef IGAMEABLE_H
#define IGAMEABLE_H

#include "igamewriter.h"


class IGameable
{
public:

  virtual void next_generation(IGameBoard *parent) = 0;
  virtual void write_game(IGameWriter *pwriter) = 0;

};


#endif  // IGAMEABLE_H
