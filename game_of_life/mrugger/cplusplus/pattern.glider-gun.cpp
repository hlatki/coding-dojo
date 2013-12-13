#include <stdio.h>
#include "pattern.glider-gun.h"


const char *PatternGliderGun::_glider_pattern[] =
{
  "..................................................",
  "..................................................",
  ".........................*........................",
  ".......................*.*........................",
  ".............**......**............**.............",
  "............*...*....**............**.............",
  ".**........*.....*...**...........................",
  ".**........*...*.**....*.*........................",
  "...........*.....*.......*........................",
  "............*...*.................................",
  ".............**...................................",
  "..................................................",
  "..................................................",
  "..................................................",
  "..................................................",
  "..................................................",
  "..................................................",
  "..................................................",
  "..................................................",
  "..................................................",
  "..................................................",
  "..................................................",
  "..................................................",
  "..................................................",
  "..................................................",
  "..................................................",
  "..................................................",
  "..................................................",
  "..................................................",
  "..................................................",
};


IQueryableBoard *PatternGliderGun::create(void)
{
  return new PatternGliderGun();
}


PatternGliderGun::PatternGliderGun(void)
: PatternBaseclass(30, 50, _glider_pattern)
{}
