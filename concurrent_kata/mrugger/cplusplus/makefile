
CC=g++
CFLAGS=-c -O3 -DNODEBUG -pthread -std=c++11
LDFLAGS=-pthread -std=c++11 -Wl,--no-as-needed

#/usr/lib/x86_64-linux-gnu/libpthread.a

#-lncurses

SOURCE_FILES =


MAIN = main

MAIN_SOURCES =	$(MAIN).cpp			\
								iterators.cpp		\
								sequencer.cpp		\
								thread.cpp			\
								accumulator.cpp

MAIN_OBJECTS = $(MAIN_SOURCES:.cpp=.o)


all:	$(MAIN)


clean:
	rm *.o
	rm $(MAIN)


$(MAIN):	$(MAIN_OBJECTS)
	$(CC) $(LDFLAGS) $(MAIN_OBJECTS) -o $@


.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
