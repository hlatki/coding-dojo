
CC=g++
CFLAGS=-c -O3
LDFLAGS=-lncurses

SOURCES=	game-of-life.cpp								\
					game.grid.cpp										\
					game.player.cpp									\
					game.board.cpp									\
					writer.console.cpp							\
					mediator.gridable-writer.cpp		\
					pattern.glider-gun.cpp					\
					pattern.switch-engine.cpp

OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=game-of-life


all: $(SOURCES) $(EXECUTABLE)


clean:
	rm *.o
	rm $(EXECUTABLE)


$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@


.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
