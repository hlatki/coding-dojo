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
#include "pattern.switch-engine.h"


static void gliders(GamePlayer *player, int_pair gameboard_size)
{
  std::auto_ptr<IGridable> pattern(PatternGliderGun::create());
  const int y_step = 40;
  int y = 0;

  while (y < (gameboard_size.y - y_step))
  {
    int_pair pattern1_position = { 0, y };
    player->add_pattern(pattern1_position, pattern.get(), false);
    y += y_step;
  }
}


static void switch_engines(GamePlayer *player, int_pair gameboard_size)
{
  std::auto_ptr<IGridable> pattern(PatternSwitchEngine::create());

  int_pair pattern1_position = { gameboard_size.x / 2, gameboard_size.y / 2 };
  player->add_pattern(pattern1_position, pattern.get(), false);
}


int main(void)
{
  int_pair gameboard_size(WriterConsole::get_window_size());
  int_pair window_origin = { 0, 0 };

  GamePlayer player(gameboard_size);

  gliders(&player, gameboard_size);
  //switch_engines(&player, gameboard_size);

  std::auto_ptr<IGameWriter> pwriter(WriterConsole::create());
  MediatorGridableToWriter writer(&player, pwriter.get());

  const int SLEEP_TIME = 10000;

  for (int a = 0; a < 2000; a++)
  {
    writer.draw(window_origin);
    player.next_generation();
    //usleep(SLEEP_TIME);
  }

  return 0;
}
