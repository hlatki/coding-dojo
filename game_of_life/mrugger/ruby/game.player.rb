require './game.types.rb'
require './game.board.rb'


class GamePlayer

  private

  @grid_current
  @grid_next


  public

  def initialize(gameboard1, gameboard2)
    @grid_current = gameboard1
    @grid_next = gameboard2
  end
  

  # Player interface

  def next_generation
    @grid_next.next_generation(@grid_current)
    temp = @grid_current
    @grid_current = @grid_next
    @grid_next = temp
  end


  # Grid interface

  def get_width
    @grid_current.get_width
  end

  def get_height
    @grid_current.get_height
  end

  def node_value(x, y)
    @grid_current.node_value(x, y)
  end

  def in_range?(x, y)
    @grid_current.in_range?(x, y)
  end

  def out_of_range?(x, y)
    @grid_current.out_of_range?(x, y)
  end

  def for_each_cell
    @grid_current.for_each_cell do |x, y|
      yield x, y
    end
  end
end
