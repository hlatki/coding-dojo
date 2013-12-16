require './game.types.rb'


class WriterConsole

  private

  @output_size


  public

  def initialize(output_size)
    @output_size = output_size
  end


  # Game writer interface

  def begin_board
    puts "\033[H"
    @output_size
  end

  def begin_row
  end

  def write_cell(celltype)
    putc "#{celltype == CellType::CELL_ALIVE ? '*' : ' '}"
  end

  def end_row
    puts ""
  end

  def end_board
  end

end
