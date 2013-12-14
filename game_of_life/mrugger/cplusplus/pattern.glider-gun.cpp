#include <stdio.h>
#include "pattern.glider-gun.h"


const int_pair PatternGliderGun::_glider_size = { 11, 38 };
const char *PatternGliderGun::_glider_pattern[] =
{
  "......................................",
  ".........................*............",
  ".......................*.*............",
  ".............**......**............**.",
  "............*...*....**............**.",
  ".**........*.....*...**...............",
  ".**........*...*.**....*.*............",
  "...........*.....*.......*............",
  "............*...*.....................",
  ".............**.......................",
  "......................................",
};


IGridable *PatternGliderGun::create(void)
{
  return new PatternGliderGun();
}


PatternGliderGun::PatternGliderGun(void)
: PatternBaseclass(_glider_size, _glider_pattern)
{}
