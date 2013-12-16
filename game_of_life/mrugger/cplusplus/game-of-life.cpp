#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <term.h>
#include <memory>
#include <curses.h>
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
  initscr();
  cbreak();
  noecho();
  nodelay(stdscr, TRUE);
  keypad(stdscr, TRUE);

  int_pair gameboard_size = { 150, 360 };\
  int_pair window_origin = { 50, 60 };
  int_pair window_size(WriterConsole::get_window_size());

  GamePlayer player(gameboard_size);

  //gliders(&player, gameboard_size);
  switch_engines(&player, gameboard_size);

  std::auto_ptr<IGameWriter> pwriter(WriterConsole::create());
  MediatorGridableToWriter writer(&player, pwriter.get());

  const int SLEEP_TIME = 10000;

  bool bdone = false;
  while (!bdone)
  {
    writer.draw(window_origin);
    player.next_generation();
    //usleep(SLEEP_TIME);

    int key = getch();
    switch (key)
    {
      case KEY_LEFT:
        if (window_origin.y > 0)
          window_origin.y--;
      break;

      case KEY_RIGHT:
        if (window_origin.y < gameboard_size.y - window_size.y)
          window_origin.y++;
      break;

      case KEY_UP:
        if (window_origin.x > 0)
          window_origin.x--;
      break;

      case KEY_DOWN:
        if (window_origin.x < gameboard_size.x - window_size.x)
          window_origin.x++;
      break;

      case KEY_BACKSPACE:
        bdone = true;
      break;
    }
  }

  endwin();

  return 0;
}
