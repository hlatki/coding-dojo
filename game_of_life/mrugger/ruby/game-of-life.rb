require './game.types.rb'
require './game.grid.rb'
require './game.board.rb'
require './game.player.rb'
require './mediator.grid_writer.rb'
require './writer.console.rb'


gridsize = Pair.new(50, 120)
gameboard1 = GameBoard.new(gridsize)
gameboard2 = GameBoard.new(gridsize)

gameplayer = GamePlayer.new(gameboard1, gameboard2)

writer = WriterConsole.new(gridsize)
mediator = MediatorGridWriter.new(gameplayer, writer)

for a in 1..4
  gameplayer.next_generation
end

mediator.draw
