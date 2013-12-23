require './game.types.rb'
require './game.grid.rb'
require './game.board.rb'
require './game.player.rb'
require './mediator.grid_writer.rb'
require './writer.console.rb'
require './pattern.glider-gun.rb'


gridsize = Pair.new(50, 120)
gameboard1 = GameBoard.new(gridsize)
gameboard2 = GameBoard.new(gridsize)

glidergun_position = Pair.new(0, 0)
glidergun = PatternGliderGun.new

gameboard1.add_pattern(glidergun_position, glidergun, false)

gameplayer = GamePlayer.new(gameboard1, gameboard2)

writer = WriterConsole.new(gridsize)
mediator = MediatorGridWriter.new(gameplayer, writer)

for a in 1..50
  gameplayer.next_generation
  mediator.draw(0, 0)
end

