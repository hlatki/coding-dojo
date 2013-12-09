#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <term.h>
#include "glider-gun.h"


#if 0
void clear_screen(void)
{
  if (!cur_term)
  {
    int result;
    setupterm( NULL, STDOUT_FILENO, &result );
    if (result <= 0) return;
    }

  putp( tigetstr( "clear" ) );
}
#endif


class GameBoard
{
private:

  static const int GRID_SIZE_X = 11;
  static const int GRID_SIZE_Y = 38;

  char _board[GRID_SIZE_X][GRID_SIZE_Y];


public:

  enum CELL_TYPES
  {
    CELL_DEAD = 0,
    CELL_ALIVE,
    CELL_ENDOF
  };


  GameBoard(void)
  {
    for (int x = 0; x < GRID_SIZE_X; x++)
      for (int y = 0; y < GRID_SIZE_Y; y++)
        _board[x][y] = glider[x][y] == '.' ? CELL_DEAD : CELL_ALIVE;
  }

  void next_generation(GameBoard *parent)
  {
    for (int x = 0; x < GRID_SIZE_X; x++)
    {
      for (int y = 0; y < GRID_SIZE_Y; y++)
      {
        calculate_cell(parent, x, y);
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
        printf("%c", _board[x][y] ? '*' : '.');
      }
      printf("\n");
    }
  }

private:

  void calculate_cell(GameBoard *parent, int x, int y)
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
      _board[x][y] = CELL_DEAD;
    else if (parent->_board[x][y] == CELL_ALIVE)
      _board[x][y] = CELL_ALIVE;
    else if (living_cell_count == 3)
      _board[x][y] = CELL_ALIVE;
    else if (living_cell_count == 2)
      _board[x][y] = CELL_DEAD;
  }


  int is_alive(GameBoard *parent, int x, int y)
  {
    if (x < 0 || x >= GRID_SIZE_X || y < 0 || y >= GRID_SIZE_Y)
      return 0;

    return parent->_board[x][y];
  }


private:

  void initialize_board(const char *starting_grid[])
  {
  }

  int initialize_cell(void)
  {
    return rand() % 2;
  }

};


int main(void)
{
  GameBoard board1, board2;

  for (int a = 0; a < 100; a++)
  {
    board1.draw_board();
    board2.next_generation(&board1);
    usleep(100000);
    board2.draw_board();
    board1.next_generation(&board2);
    usleep(100000);
  }
}
