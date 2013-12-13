#ifndef PATTERN_GLIDER_GUN_H
#define PATTERN_GLIDER_GUN_H


#include "pattern.baseclass.h"


class PatternGliderGun : public PatternBaseclass
{
public:

  static IQueryableBoard *create(void);


private:

  static char **_glider_pattern;


private:

  PatternGliderGun(void);

};


#endif  // PATTERN_GLIDER_GUN_H
