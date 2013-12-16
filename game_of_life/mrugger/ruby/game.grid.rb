
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
    raise RangeError, "x or y (#{x}, #{y}) are out of range" if out_of_range?(x, y)
    @grid[x][y]
  end

  def in_range?(x, y)
    x >= 0 && x < get_height && y >= 0 && y < get_width
  end

  def out_of_range?(x, y)
    x < 0 || x >= get_height || y < 0 || y >= get_width
  end

  def for_each_cell
    for x in 0..get_height-1
      for y in 0..get_width-1
        yield x, y
      end
    end
  end


  protected

  def set_node_value(x, y, value)
    raise RangeError, "x or y (#{x}, #{y}) are out of range" if out_of_range?(x, y)
    @grid[x][y] = value
  end

end
