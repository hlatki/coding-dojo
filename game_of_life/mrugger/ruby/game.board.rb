require './game.types.rb'
require './game.grid.rb'


class GameBoard < GameGrid

  # GameBoard interface

  def add_pattern(position, pattern_grid, btransparent)
  end

  def next_generation(parent_board)
    for_each_cell do |x, y|
      new_cell_value = parent_board.calculate_child_cell(x, y)
      set_node_value(x, y, new_cell_value)
    end
  end


  protected

  def calculate_child_cell(x, y)
    living_cell_count = 0

    living_cell_count  = is_alive(x-1, y-1);
    living_cell_count += is_alive(x-1, y);
    living_cell_count += is_alive(x-1, y+1);
    living_cell_count += is_alive(x,   y-1);
    living_cell_count += is_alive(x,   y+1);
    living_cell_count += is_alive(x+1, y-1);
    living_cell_count += is_alive(x+1, y);
    living_cell_count += is_alive(x+1, y+1);

    if (living_cell_count < 2 || living_cell_count > 3) then
      return CellType::CELL_DEAD;
    elsif (node_value(x, y) == CellType::CELL_ALIVE) then
      return CellType::CELL_ALIVE;
    elsif (living_cell_count == 3) then
      return CellType::CELL_ALIVE;
    else
      return CellType::CELL_DEAD;
    end
  end

  def is_alive(x, y)
    return node_value(x, y) if in_range?(x, y)
    return CellType::CELL_DEAD
  end

end
