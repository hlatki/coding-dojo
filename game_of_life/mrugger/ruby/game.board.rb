require './game.types.rb'
require './game.grid.rb'


class GameBoard < GameGrid

  # GameBoard interface

  def add_pattern(position, pattern_grid, btransparent)
  end

  def next_generation(parent_grid)
    for_each_cell do |x, y|
      new_cell_value = calculate_cell(parent_grid, x, y)
      set_node_value(x, y, new_cell_value)
    end
#    for x in 0..get_height-1
#      for y in 0..get_width-1
#        new_cell_value = calculate_cell(parent_grid, x, y)
#        set_node_value(x, y, new_cell_value)
#      end
#    end
  end


  private

  def calculate_cell(parent_grid, x, y)
    living_cell_count = 0

    living_cell_count  = is_alive(parent_grid, x-1, y-1);
    living_cell_count += is_alive(parent_grid, x-1, y);
    living_cell_count += is_alive(parent_grid, x-1, y+1);
    living_cell_count += is_alive(parent_grid, x,   y-1);
    living_cell_count += is_alive(parent_grid, x,   y+1);
    living_cell_count += is_alive(parent_grid, x+1, y-1);
    living_cell_count += is_alive(parent_grid, x+1, y);
    living_cell_count += is_alive(parent_grid, x+1, y+1);

    if (living_cell_count < 2 || living_cell_count > 3) then
      return CellType::CELL_DEAD;
    elsif (parent_grid.node_value(x, y) == CellType::CELL_ALIVE) then
      return CellType::CELL_ALIVE;
    elsif (living_cell_count == 3) then
      return CellType::CELL_ALIVE;
    else
      return CellType::CELL_DEAD;
    end
  end

  def is_alive(parent_grid, x, y)
    return parent_grid.node_value(x, y) if parent_grid.in_range?(x, y)
    return CellType::CELL_DEAD
  end

end
