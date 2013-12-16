
class GameGrid

  private

  @gridsize
  @grid


  public

  def initialize(gridsize)
    @gridsize = gridsize
    @grid = Array.new(@gridsize.x) { |i| Array.new(@gridsize.y) { |i| 0 } }
  end


  # Grid interface

  def get_width
    @gridsize.y
  end

  def get_height
    @gridsize.x
  end

  def node_value(x, y)
    raise RangeError, "x (#{x}) parameter out of range" if x < 0 || x >= get_height
    raise RangeError, "y (#{y}) parameter out of range" if y < 0 || y >= get_width
    @grid[x][y]
  end

  def in_range?(x, y)
    return false if x < 0 || x >= get_height || y < 0 || y >= get_width
    return true
  end


  protected

  def set_node_value(x, y, value)
    raise RangeError, "x (#{x}) parameter out of range" if x < 0 || x >= get_height
    raise RangeError, "y (#{y}) parameter out of range" if y < 0 || y >= get_width
    @grid[x][y] = value
  end

end
