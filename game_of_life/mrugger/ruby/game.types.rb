
module CellType

  CELL_DEAD = 0
  CELL_ALIVE = 1
  
end


class Pair

  attr_accessor :x
  attr_accessor :y

  def initialize(x, y)
    @x = x
    @y = y
  end

end

