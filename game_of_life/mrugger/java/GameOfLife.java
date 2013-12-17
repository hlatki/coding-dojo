

class GameOfLife
{
  public static void main(String[] args)
  {
    Pair boardsize = new Pair(50, 120);
    PatternGliderGun glidergun = new PatternGliderGun();
    Pair glidergun_position = new Pair(0, 0);

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

    WriterStream outstream = new WriterStream(boardsize, "glider.txt");
    MediatorGridWriter med = new MediatorGridWriter(player, outstream);
    med.draw(window_position);

    System.out.format("size_x = %d, size_y = %d\n", player.get_height(), player.get_width());
  }
}
