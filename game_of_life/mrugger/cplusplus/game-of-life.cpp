#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <term.h>
#include "game-types.h"
#include "game-player.h"
#include "consolewriter.h"
#include "queryabletowriter.h"
#include "pattern.glider-gun.h"


int main(void)
{
  IQueryableBoard *glidergun = PatternGliderGun::create();
  int_point gameboard_size = { 50, 70 };
  int_point glidergun_position = { 5, 10 };
  GamePlayer board(gameboard_size, glidergun_position, glidergun);

  IGameWriter *pwriter = ConsoleWriter::create();
  QueryableToWriter writer(&board, pwriter);

  const int SLEEP_TIME = 10000;

  for (int a = 0; a < 1000; a++)
  {
    writer.draw();
    board.next_generation();
    usleep(SLEEP_TIME);
  }

  delete pwriter;
  delete glidergun;
}

#if 0
int main(void)
{
  IQueryableBoard *glidergun = PatternGliderGun::create();
  GameBoard board1(50, 70, 5, 10, glidergun);
  GameBoard board2(&board1);
  IGameWriter *pwriter = ConsoleWriter::create();
  QueryableToWriter writer1(&board1, pwriter);
  QueryableToWriter writer2(&board2, pwriter);
  const int SLEEP_TIME = 10000;

  for (int a = 0; a < 1000; a++)
  {
    writer1.draw();
    board2.next_generation(&board1);
    usleep(SLEEP_TIME);

    writer2.draw();
    board1.next_generation(&board2);
    usleep(SLEEP_TIME);
  }

  delete pwriter;
  delete glidergun;
}
#endif
