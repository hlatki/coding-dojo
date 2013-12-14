#ifndef GAME_TYPES_H
#define GAME_TYPES_H


enum CELL_TYPE
{
  CELL_DEAD = 0,
  CELL_ALIVE,
  CELL_ENDOF
};


struct int_point
{
  int x, y;
};


#endif  // GAME_TYPES_H
