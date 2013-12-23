require './game.types.rb'


class PatternGliderGun

  private

  @width
  @height
  @pattern


  public

  def initialize
    @width = 38
    @height = 11
    @pattern = Array.new(@height)
    @pattern[ 0] = "......................................"
    @pattern[ 1] = ".........................*............"
    @pattern[ 2] = ".......................*.*............"
    @pattern[ 3] = ".............**......**............**."
    @pattern[ 4] = "............*...*....**............**."
    @pattern[ 5] = ".**........*.....*...**..............."
    @pattern[ 6] = ".**........*...*.**....*.*............"
    @pattern[ 7] = "...........*.....*.......*............"
    @pattern[ 8] = "............*...*....................."
    @pattern[ 9] = ".............**......................."
    @pattern[10] = "......................................"
  end


  # Grid interface

  def get_width
    @width
  end

  def get_height
    @height
  end

  def node_value(x, y)
    raise RangeError, "x or y (#{x}, #{y}) are out of range" if out_of_range?(x, y)
    @pattern[x][y] == '*' ? CellType::CELL_ALIVE : CellType::CELL_DEAD
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

end
