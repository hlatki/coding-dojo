

class MediatorGridWriter
{
  private IGridable _grid;
  private IWriteable _writer;

  public MediatorGridWriter(IGridable grid, IWriteable writer)
  {
    _grid = grid;
    _writer = writer;
  }


  public void draw(Pair position)
  {
    Pair window_size = _writer.begin_board();
    for (int x = 0; x < window_size.x; x++)
    {
      _writer.begin_row();
      for (int y = 0; y < window_size.y; y++)
      {
        _writer.write_cell(_grid.node_value(position.x + x, position.y + y));
      }
      _writer.end_row();
    }
    _writer.end_board();
  }
}
