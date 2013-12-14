
CC=g++
CFLAGS=-c

SOURCES=	game-of-life.cpp				\
					game.grid.cpp						\
					game.player.cpp					\
					game.board.cpp					\
					consolewriter.cpp				\
					queryabletowriter.cpp		\
					pattern.glider-gun.cpp

OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=game-of-life


all: $(SOURCES) $(EXECUTABLE)


clean:
	rm *.o
	rm $(EXECUTABLE)


$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@


.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
