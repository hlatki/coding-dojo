#ifndef PATTERN_BASECLASS_H
#define PATTERN_BASECLASS_H


#include "iqueryableboard.h"


class PatternBaseclass : public IQueryableBoard
{
private:

  int _x_size;
  int _y_size;
  const char **_pattern;


protected:

  PatternBaseclass(int x_size, int y_size, const char **pattern);


protected:  // IQueryableBoard

  virtual int get_width(void);
  virtual int get_height(void);

  virtual CELL_TYPE node_value(int x, int y);

};


#endif  // PATTERN_BASECLASS_H
