

class GameBoard extends GameGrid
{
  public GameBoard(Pair gridsize)
  {
    super(gridsize);
  }

  public void add_pattern(Pair position, IGridable pattern)
  {
    for (int x = 0; x < pattern.get_height(); x++)
    {
      for (int y = 0; y < pattern.get_width(); y++)
      {
        set_node_value(position.x + x, position.y + y, pattern.node_value(x, y));
      }
    }
  }

  public void next_generation(GameBoard parent)
  {
    for (int x = 0; x < get_height(); x++)
    {
      for (int y = 0; y < get_width(); y++)
      {
        set_node_value(x, y, parent.calculate_next_cell(x, y));
      }
    }
  }

  private CellType calculate_next_cell(int x, int y)
  {
    int living_cell_count;

    living_cell_count  = is_alive(x-1, y-1);
    living_cell_count += is_alive(x-1, y);
    living_cell_count += is_alive(x-1, y+1);
    living_cell_count += is_alive(x,   y-1);
    living_cell_count += is_alive(x,   y+1);
    living_cell_count += is_alive(x+1, y-1);
    living_cell_count += is_alive(x+1, y);
    living_cell_count += is_alive(x+1, y+1);

    if (living_cell_count < 2 || living_cell_count > 3)
      return CellType.CELL_DEAD;
    else if (node_value(x, y) == CellType.CELL_ALIVE)
      return CellType.CELL_ALIVE;
    else if (living_cell_count == 3)
      return CellType.CELL_ALIVE;
    else
      return CellType.CELL_DEAD;
  }

  private int is_alive(int x, int y)
  {
    if (in_range(x, y))
      return node_value(x, y) == CellType.CELL_ALIVE ? 1 : 0;
    else
      return 0;
  }
}