#ifndef GAME_TYPES_H
#define GAME_TYPES_H


enum CELL_TYPE
{
  CELL_DEAD = 0,
  CELL_ALIVE,
  CELL_ENDOF
};


enum CHARCELL_MAP
{
  CHARCELL_DEAD = ' ',
  CHARCELL_ALIVE = '*',
  CHARCELL_ENDOF
};


struct int_pair
{
  int x, y;
};


#endif  // GAME_TYPES_H
