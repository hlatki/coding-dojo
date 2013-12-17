

class GamePlayer implements IGridable
{
  private GameBoard current_board;
  private GameBoard next_board;

  public GamePlayer(GameBoard board)
  {
    current_board = board;
    Pair size = new Pair(current_board.get_height(), current_board.get_width());
    next_board = new GameBoard(size);
  }


  public void next_generation()
  {
    next_board.next_generation(current_board);
    GameBoard temp = current_board;
    current_board = next_board;
    next_board = temp;
  }


  // IGridable

  public int get_width()
  {
    return current_board.get_width();
  }

  public int get_height()
  {
    return current_board.get_height();
  }

  public CellType node_value(int x, int y)
  {
    return current_board.node_value(x, y);
  }

  public boolean in_range(int x, int y)
  {
    return current_board.in_range(x, y);
  }

  public boolean out_of_range(int x, int y)
  {
    return current_board.out_of_range(x, y);
  }
}
