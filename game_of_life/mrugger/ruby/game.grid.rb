require 'matrix'

class GameGrid

  @grid

  def initialize(gridsize)
    @grid = Matrix.build(gridsize.x, gridsize.y) { 0 }
  end


  # Grid interface

  def get_width
    @grid.column_size
  end

  def get_height
    @grid.row_size
  end

  def node_value(x, y)
    raise RangeError, 'x parameter out of range' if x < 0 || x >= get_height
    raise RangeError, 'y parameter out of range' if y < 0 || y >= get_width
    @grid.component(x, y)
  end

  def in_range?(x, y)
    return false if x < 0 || x >= get_height || y < 0 || y >= get_width
    return true
  end


  protected

  def set_node_value(x, y, value)
  end

end
