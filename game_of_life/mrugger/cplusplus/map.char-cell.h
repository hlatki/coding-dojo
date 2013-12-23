#ifndef MAP_CHAR_CELL_H
#define MAP_CHAR_CELL_H


#include <stdexcept>
#include "game.types.h"


class MapCharCell
{
public:

  static inline CELL_TYPE char_to_cell(char c)
  {
    CELL_TYPE cell;

    switch (c)
    {
      case '.':
      case ' ':
        cell = CELL_DEAD;
        break;

      case '*':
        cell = CELL_ALIVE;
        break;

      default:
        throw std::invalid_argument("c is invalid character");
        break;
    }

    return cell;
  }


  static inline char cell_to_char(CELL_TYPE cell)
  {
    char c;

    switch (cell)
    {
      case CELL_DEAD:
        c = ' ';
        break;

      case CELL_ALIVE:
        c = '*';
        break;

      default:
        throw std::invalid_argument("cell has invalid value");
        break;
    }

    return c;
  }

};


#endif  // MAP_CHAR_CELL_H
