

class GameOfLife
{
  public static void main(String[] args)
  {
    Pair boardsize = new Pair(50, 120);
    GameBoard board1 = new GameBoard(boardsize);
    GameBoard board2 = new GameBoard(boardsize);
    for (int a = 0; a < 100; a++)
    {
      board2.next_generation(board1);
      board1.next_generation(board2);
    }
    System.out.format("size_x = %d, size_y = %d\n", board1.get_height(), board1.get_width());
  }
}
