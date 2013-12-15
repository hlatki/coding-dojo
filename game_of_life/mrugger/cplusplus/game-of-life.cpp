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


static void gliders(GamePlayer *player)
{
  std::auto_ptr<IGridable> pattern(PatternGliderGun::create());

  int_pair pattern1_position = { 0, 0 };
  player->add_pattern(pattern1_position, pattern.get(), false);

  int_pair pattern2_position = { 0, 40 };
  player->add_pattern(pattern2_position, pattern.get(), false);

  int_pair pattern3_position = { 0, 80 };
  player->add_pattern(pattern3_position, pattern.get(), false);
}


static void switch_engines(GamePlayer *player)
{
  std::auto_ptr<IGridable> pattern(PatternSwitchEngine::create());

  int_pair pattern1_position = { 75, 180 };
  player->add_pattern(pattern1_position, pattern.get(), false);
}


int main(void)
{
  int_pair gameboard_size = { 150, 360 };
  int_pair window_origin = { 50, 120 };
  int_pair window_size = { 50, 120 };

  GamePlayer player(gameboard_size);

  //gliders(&player);
  switch_engines(&player);

  std::auto_ptr<IGameWriter> pwriter(WriterConsole::create(window_size));
  MediatorGridableToWriter writer(&player, pwriter.get());

  const int SLEEP_TIME = 10000;

  for (int a = 0; a < 1000; a++)
  {
    writer.draw(window_origin, window_size);
    player.next_generation();
    //usleep(SLEEP_TIME);
  }

  return 0;
}
