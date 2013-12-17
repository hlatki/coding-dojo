

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
    for (int a = 0; a < 1000; a++)
    {
      player.next_generation();
      mediator.draw(window_position);
    }

    WriterStream streamwriter = new WriterStream(boardsize, "glider.txt");
    mediator.set_writer(streamwriter);
    mediator.draw(window_position);
  }
}
