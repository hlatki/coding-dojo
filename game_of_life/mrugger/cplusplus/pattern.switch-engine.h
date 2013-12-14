#ifndef PATTERN_SWITCH_ENGINE_H
#define PATTERN_SWITCH_ENGINE_H


//#include "pattern.baseclass.h"
#include "game.grid.h"


class PatternSwitchEngine : public GameGrid
{
public:

  static IGridable *create(void);


private:

  static const int_pair _glider_size;
  static const char *_glider_pattern[];


private:

  PatternSwitchEngine(void);

};


#endif  // PATTERN_SWITCH_ENGINE_H
