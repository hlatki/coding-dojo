require 'test/unit'

class GameOfLife
  def initialize(gen)
    @rows = gen.split("\n")
    @next_gen = []
  end

  def get_next_gen()
    @rows.each_with_index do |row, row_index|
      next_gen_row = ''
      row.size.times do |column_index|
        next_gen_row += next_gen_pop(row_index, column_index)
      end
      @next_gen[row_index] = next_gen_row
    end
    @next_gen.join("\n")
  end

  def count_alive_neighbors(row, column)
    count = count_alive_neighbor_at(row - 1, column - 1)
    count += count_alive_neighbor_at(row - 1, column)
    count += count_alive_neighbor_at(row - 1, column + 1)
    count += count_alive_neighbor_at(row, column - 1)
    count += count_alive_neighbor_at(row, column + 1)
    count += count_alive_neighbor_at(row + 1, column - 1)
    count += count_alive_neighbor_at(row + 1, column)
    count += count_alive_neighbor_at(row + 1, column + 1)
  end

  def count_alive_neighbor_at(row, column)
    if row < 0 || column < 0
      0
    elsif alive? row, column
      1
    else
      0
    end
  end

  def alive?(row, column)
    begin
      @rows[row][column].eql?('*')
    rescue
      false
    end
  end

  def alive_next_gen?(row, column)
    neighbor_count = count_alive_neighbors(row, column)
    if neighbor_count == 3
      true
    elsif alive?(row, column) && neighbor_count == 2
      true
    else
      false
    end
  end

  def next_gen_pop(row, column)
    if alive_next_gen? row, column
      '*'
    else
      '.'
    end
  end
end

class GameOfLifeTests < Test::Unit::TestCase
  def setup
    gen = '''......*.
....*.**
...**...
........
...***..
..*.**..'''

    @game = GameOfLife.new(gen)
  end

  def test_alive
    assert(!@game.alive?(1, 1))
    assert(@game.alive?(2, 4))
    assert(@game.alive?(1, 4))
    assert(!@game.alive?(10, 10))
  end

  def test_count_neighbors
    assert_equal 3, @game.count_alive_neighbors(1, 3)
    assert_equal 0, @game.count_alive_neighbors(0, 0)
    assert_equal 2, @game.count_alive_neighbors(2, 3)
    assert_equal 2, @game.count_alive_neighbors(2, 4)
    assert_equal 2, @game.count_alive_neighbors(1, 4)
  end

  def test_alive_next_gen
    # birth
    assert @game.alive_next_gen?(1, 3)

    assert !@game.alive_next_gen?(0, 0)
    assert @game.alive_next_gen?(1, 4)
    assert !@game.alive_next_gen?(2, 2)
    assert !@game.alive_next_gen?(4, 4)
    assert !@game.alive_next_gen?(5, 3)
    assert !@game.alive_next_gen?(5, 4)
    assert @game.alive_next_gen?(5, 5)
    assert !@game.alive_next_gen?(5, 6)
    assert !@game.alive_next_gen?(5, 7)
  end

  def test_base_case
    gen = '''........
....*...
...**...
........'''
    next_gen = '''........
...**...
...**...
........'''
    game = GameOfLife.new(gen)
    assert_equal next_gen, game.get_next_gen()
  end

end