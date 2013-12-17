

class PatternGliderGun implements IGridable
{
  private Pair _extent = new Pair(11, 38);
  private String[] _pattern =
  {
    "......................................",
    ".........................*............",
    ".......................*.*............",
    ".............**......**............**.",
    "............*...*....**............**.",
    ".**........*.....*...**...............",
    ".**........*...*.**....*.*............",
    "...........*.....*.......*............",
    "............*...*.....................",
    ".............**.......................",
    "......................................"
  };


  public PatternGliderGun()
  {}


  // IGridable

  public int get_width()
  {
    return _extent.y;
  }

  public int get_height()
  {
    return _extent.x;
  }

  public CellType node_value(int x, int y)
  {
    if (in_range(x, y))
    {
      String row = _pattern[x];
      return row.charAt(y) == '*' ? CellType.CELL_ALIVE : CellType.CELL_DEAD;
    }
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

}
