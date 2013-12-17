

class GameOfLife
{
  public static void main(String[] args)
  {
    Pair boardsize = new Pair(50, 120);
    GameBoard board = new GameBoard(boardsize);
    GamePlayer player = new GamePlayer(board);

    WriterConsole writer = new WriterConsole(boardsize);
    MediatorGridWriter mediator = new MediatorGridWriter(player, writer);

    Pair window_position = new Pair(0, 0);
    for (int a = 0; a < 10; a++)
    {
      player.next_generation();
      mediator.draw(window_position);
    }

    System.out.format("size_x = %d, size_y = %d\n", player.get_height(), player.get_width());
  }
}
