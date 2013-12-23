#include <stdio.h>
#include "pattern.switch-engine.h"


const int_pair PatternSwitchEngine::_glider_size = { 7, 7 };
const char *PatternSwitchEngine::_glider_pattern[] =
{
  ".......",
  ".***.*.",
  ".*.....",
  "....**.",
  "..**.*.",
  ".*.*.*.",
  ".......",
};


IGridable *PatternSwitchEngine::create(void)
{
  return new PatternSwitchEngine();
}


PatternSwitchEngine::PatternSwitchEngine(void)
: GameGrid(_glider_size, _glider_pattern)
{}
