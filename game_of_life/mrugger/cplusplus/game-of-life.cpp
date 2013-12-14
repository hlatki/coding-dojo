#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <term.h>
#include <memory>
#include "game.types.h"
#include "game.player.h"
#include "writer.console.h"
#include "mediator.gridable-writer.h"
#include "pattern.glider-gun.h"


int main(void)
{
  int_pair gameboard_size = { 50, 70 };
  int_pair pattern_position = { 0, 0 };
  std::auto_ptr<IGridable> pattern(PatternGliderGun::create());
  GamePlayer board(gameboard_size, pattern_position, pattern.get());

  std::auto_ptr<IGameWriter> pwriter(WriterConsole::create());
  MediatorGridableToWriter writer(&board, pwriter.get());

  const int SLEEP_TIME = 10000;

  for (int a = 0; a < 1000; a++)
  {
    writer.draw();
    board.next_generation();
    usleep(SLEEP_TIME);
  }

  return 0;
}
