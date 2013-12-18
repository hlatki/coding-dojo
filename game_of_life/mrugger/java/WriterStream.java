import java.io.OutputStream;
import java.io.FileOutputStream;
import java.io.IOException;


class WriterStream implements IWriteable
{
  private Pair _window_size;
  private OutputStream _outstream;
  private String _filename;


  public WriterStream(Pair window_size, String filename)
  {
    _window_size = window_size;
    _outstream = null;
    _filename = filename;
  }


  // IWriteable interface

  public Pair begin_board()
  {
    try
    {
      _outstream = new FileOutputStream(filename);
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
      _outstream.write(cellvalue.to_file());
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
  {
    try
    {
      if (_outstream != null)
      {
        _outstream.close();
      }
    }

    catch (IOException e)
    {
      e.printStackTrace();
    }
  }
}
