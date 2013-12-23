

class GameOfLife
{
  public static void main(String[] args)
  {
    Pair boardsize = new Pair(50, 120);
    Pair glidergun_position = new Pair(0, 0);
    PatternGliderGun glidergun = new PatternGliderGun();

    GameBoard board = new GameBoard(boardsize);
    board.add_pattern(glidergun_position, glidergun);

    GamePlayer player = new GamePlayer(board);
    WriterConsole writer = new WriterConsole(boardsize);
    MediatorGridWriter mediator = new MediatorGridWriter(player, writer);

    Pair window_position = new Pair(0, 0);
    for (int a = 0; a < 100; a++)
    {
      player.next_generation();
      mediator.draw(window_position);
    }
  }


  private void WriteGliderGunToFile()
  {
    PatternGliderGun glidergun = new PatternGliderGun();
    Pair glidergun_size = new Pair(glidergun.get_height(), glidergun.get_width());
    WriterStream glidergun_writer = new WriterStream(glidergun_size, "glidergun.txt");
    MediatorGridWriter glidergun_mediator = new MediatorGridWriter(glidergun, glidergun_writer);
    glidergun_mediator.draw(new Pair(0, 0));
  }
}
