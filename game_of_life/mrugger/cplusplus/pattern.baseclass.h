#ifndef PATTERN_BASECLASS_H
#define PATTERN_BASECLASS_H


#include "game-types.h"
#include "iqueryableboard.h"


class PatternBaseclass : public IQueryableBoard
{
private:

  int_pair _pattern_size;
  const char **_pattern;


protected:

  PatternBaseclass(void);
  PatternBaseclass(int_pair pattern_size, const char **pattern);

  void initialize(int_pair pattern_size, const char **pattern);


protected:  // IQueryableBoard

  virtual int get_width(void);
  virtual int get_height(void);

  virtual CELL_TYPE node_value(int x, int y);

};


#endif  // PATTERN_BASECLASS_H
