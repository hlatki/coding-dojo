require './game.types.rb'


class MediatorGridWriter

  private

  @grid
  @writer


  public

  def initialize(grid, writer)
    @grid = grid
    @writer = writer
  end


  # Writer interface

  def draw
    output_size = @writer.begin_board
    for x in 0..output_size.x-1
      @writer.begin_row
      for y in 0..output_size.y-1
        @writer.write_cell(@grid.node_value(x, y))
      end
      @writer.end_row
    end
    @writer.end_board
  end

end
