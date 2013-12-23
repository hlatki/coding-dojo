

class Pair
{
  public int x;
  public int y;

  public Pair(int x_val, int y_val)
  {
    x = x_val;
    y = y_val;
  }

  public Pair(Pair other)
  {
    x = other.x;
    y = other.y;
  }

  public String to_string()
  {
    return Integer.toString(x) + " " + Integer.toString(y);
  }
}