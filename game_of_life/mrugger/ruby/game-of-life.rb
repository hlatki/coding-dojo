require './game.types.rb'
require './game.grid.rb'
require './game.board.rb'


gridsize = Pair.new(150, 360)
gameboard1 = GameBoard.new(gridsize)
gameboard2 = GameBoard.new(gridsize)

for a in 1..10
  gameboard2.next_generation(gameboard1)
  gameboard1.next_generation(gameboard2)
end
