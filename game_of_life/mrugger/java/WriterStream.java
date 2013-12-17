import java.io.OutputStream;
import java.io.FileOutputStream;
import java.io.IOException;


class WriterStream implements IWriteable
{
  private Pair _window_size;
  OutputStream _outstream;


  public WriterStream(Pair window_size, OutputStream outstream)
  {
    _window_size = window_size;
    _outstream = outstream;
  }


  public WriterStream(Pair window_size, String filename)
  {
    _window_size = window_size;
    try
    {
      _outstream = new FileOutputStream(filename);
    }

    catch (IOException e)
    {
      e.printStackTrace();
    }
  }


  // IWriteable interface

  public Pair begin_board()
  {
    try
    {
      _outstream.write(_window_size.to_string().getBytes());
      _outstream.write('\n');
    }

    catch (IOException e)
    {
      e.printStackTrace();
    }

    return _window_size;
  }

  public void begin_row()
  {}

  public void write_cell(CellType cellvalue)
  {
    try
    {
      _outstream.write(cellvalue.to_char());
    }

    catch (IOException e)
    {
      e.printStackTrace();
    }
  }

  public void end_row()
  {
    try
    {
      _outstream.write('\n');
    }

    catch (IOException e)
    {
      e.printStackTrace();
    }
  }

  public void end_board()
  {}
}
