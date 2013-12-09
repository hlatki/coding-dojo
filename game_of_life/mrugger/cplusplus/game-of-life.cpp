#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <term.h>
#include "glider-gun.h"


class GameBoard
{
public:

  enum CELL_TYPE
  {
    CELL_DEAD = 0,
    CELL_ALIVE,
    CELL_ENDOF
  };


private:

  int GRID_SIZE_X;
  int GRID_SIZE_Y;

  CELL_TYPE *_board;


public:


  GameBoard(int x_width, int y_width, const char *pattern[])
  {
    GRID_SIZE_X = x_width;
    GRID_SIZE_Y = y_width;
    _board = new CELL_TYPE[x_width*y_width];

    for (int x = 0; x < GRID_SIZE_X; x++)
      for (int y = 0; y < GRID_SIZE_Y; y++)
        node(x, y) = glider[x][y] == '.' ? CELL_DEAD : CELL_ALIVE;
  }


  void next_generation(GameBoard *parent)
  {
    for (int x = 0; x < GRID_SIZE_X; x++)
    {
      for (int y = 0; y < GRID_SIZE_Y; y++)
      {
        node(x, y) = calculate_cell(parent, x, y);
      }
    }
  }


  void draw_board(void)
  {
    printf("\033[H\033[J");
    //clear_screen();

    for (int x = 0; x < GRID_SIZE_X; x++)
    {
      for (int y = 0; y < GRID_SIZE_Y; y++)
      {
        printf("%c", node(x, y) ? '*' : ' ');
      }
      printf("\n");
    }
  }


private:

  CELL_TYPE &node(int x, int y)
  {
    if (x < 0 || x >= GRID_SIZE_X || y < 0 || y >= GRID_SIZE_Y)
    {
      printf("Index out of range.\n");
      exit(1);
    }

    return _board[GRID_SIZE_X * y + x];
  }


  CELL_TYPE calculate_cell(GameBoard *parent, int x, int y)
  {
    int living_cell_count;

    living_cell_count  = is_alive(parent, x-1, y-1);
    living_cell_count += is_alive(parent, x-1, y);
    living_cell_count += is_alive(parent, x-1, y+1);
    living_cell_count += is_alive(parent, x,   y-1);
    living_cell_count += is_alive(parent, x,   y+1);
    living_cell_count += is_alive(parent, x+1, y-1);
    living_cell_count += is_alive(parent, x+1, y);
    living_cell_count += is_alive(parent, x+1, y+1);

    if (living_cell_count < 2 || living_cell_count > 3)
      return CELL_DEAD;
    else if (parent->node(x, y) == CELL_ALIVE)
      return CELL_ALIVE;
    else if (living_cell_count == 3)
      return CELL_ALIVE;
    else
      return CELL_DEAD;
  }


  int is_alive(GameBoard *parent, int x, int y)
  {
    if (x < 0 || x >= GRID_SIZE_X || y < 0 || y >= GRID_SIZE_Y)
      return 0;

    return parent->node(x, y);
  }

};


int main(void)
{
  GameBoard board1(GLIDER_Y, GLIDER_X, glider), board2(GLIDER_Y, GLIDER_X, glider);

  for (int a = 0; a < 1000; a++)
  {
    board1.draw_board();
    board2.next_generation(&board1);
    usleep(50000);
    board2.draw_board();
    board1.next_generation(&board2);
    usleep(50000);
  }
}
