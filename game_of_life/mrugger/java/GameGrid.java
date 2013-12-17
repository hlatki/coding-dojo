

class GameGrid implements IGridable
{
  private Pair _gridsize;
  private CellType[][] _grid;


  public GameGrid(Pair gridsize)
  {
    _gridsize = gridsize;
    _grid = new CellType[_gridsize.x][_gridsize.y];
  }


  // IGridable

  public int get_width()
  {
    return _gridsize.y;
  }

  public int get_height()
  {
    return _gridsize.x;
  }

  public CellType node_value(int x, int y)
  {
    if (in_range(x, y))
      return _grid[x][y];
    else
      throw new RuntimeException("x or y out of range");
  }

  public boolean in_range(int x, int y)
  {
    return x >= 0 && x < get_height() && y >= 0 && y < get_width();
  }

  public boolean out_of_range(int x, int y)
  {
    return x < 0 || x >= get_height() || y < 0 || y >= get_width();
  }

  protected void set_node_value(int x, int y, CellType cell_value)
  {
    if (in_range(x, y))
      _grid[x][y] = cell_value;
    else
      throw new RuntimeException("x or y out of range");
  }
}