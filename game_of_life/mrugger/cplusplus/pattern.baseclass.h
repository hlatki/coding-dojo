#ifndef PATTERN_BASECLASS_H
#define PATTERN_BASECLASS_H


#include <memory>
#include "game.types.h"
#include "igridable.h"


class PatternBaseclass : public IGridable
{
private:

  int_pair _pattern_size;
  std::auto_ptr<CELL_TYPE> _pattern;


protected:

  PatternBaseclass(void);
  PatternBaseclass(int_pair pattern_size, const char **pattern);

  void initialize(int_pair pattern_size, const char **pattern);
  CELL_TYPE &node(int x, int y);


protected:  // IGridable

  virtual int get_width(void);
  virtual int get_height(void);

  virtual CELL_TYPE node_value(int x, int y);

};


#endif  // PATTERN_BASECLASS_H
