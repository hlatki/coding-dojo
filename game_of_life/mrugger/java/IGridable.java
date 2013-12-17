

interface IGridable
{
  int get_width();
  int get_height();
  CellType node_value(int x, int y);
  boolean in_range(int x, int y);
  boolean out_of_range(int x, int y);
}
