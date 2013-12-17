

interface IWriteable
{
  Pair begin_board();
  void begin_row();
  void write_cell(CellType cellvalue);
  void end_row();
  void end_board();
}
