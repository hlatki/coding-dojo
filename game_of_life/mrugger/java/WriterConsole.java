

class WriterConsole implements IWriteable
{
  private Pair _window_size;


  public WriterConsole(Pair window_size)
  {
    _window_size = window_size;
  }


  // IWriteable interface

  public Pair begin_board()
  {
    System.out.print("\033[H");
    return _window_size;
  }

  public void begin_row()
  {}

  public void write_cell(CellType cellvalue)
  {
    System.out.print(cellvalue.to_char());//(cellvalue == CellType.CELL_ALIVE ? '*' : ' ');
  }

  public void end_row()
  {
    System.out.println();
  }

  public void end_board()
  {}
}
