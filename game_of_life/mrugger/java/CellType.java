


enum CellType
{
  CELL_DEAD(0),
  CELL_ALIVE(1);

  private int _value;

  private CellType(int value)
  {
    _value = value;
  }

  public char to_char()
  {
    return _value == 1 ? '*' : ' ';
  }
}
