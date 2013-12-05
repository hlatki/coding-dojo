#!/usr/bin/env python
import sys

DEAD, ALIVE = range(2)

# play with these and lets see what happens
neighbor_range = (-1,1)
stay_alive = (2,3)
birth = 3

class Life:
    def __init__(self, size, board):
        self._board = board
        self._size = size

    def getNeighbors(self, x, y, rng=neighbor_range):
        neighbors = []
        for row in self._board[max(x+rng[0], 0):min(x+rng[1], self._size[0])+1]:
            neighbors.extend(row[max(y+rng[0], 0):min(y+rng[1], self._size[1])+1])
        return neighbors

    def getLivingNeighbors(self, x, y):
        neighbors = self.getNeighbors(x, y)
        return sum(neighbors) #yes its that easy

    def live(self, gens=1):
        for g in range(gens):
            #this gives us a zeroed n x m board
            next = [[0 for j in range(self._size[1])] for i in range(self._size[0])]
            for (i,row) in enumerate(self._board):
                for (j,cell) in enumerate(row):
                    #yes we count ourselves in our neighbors. don't ask.
                    living = self.getLivingNeighbors(i,j) - cell
                    if cell == ALIVE:
                        if living in stay_alive:
                            next[i][j] = ALIVE
                    if cell == DEAD:
                        if living == birth:
                            next[i][j] = ALIVE

            self._board = next

def readBoard(file):
    with open(file) as f:
        lines = [line.strip() for line in f]
        (x, y) = [int(i) for i in lines.pop(0).split()]
        assert len(lines) == x, "expected %d, actual %d" % (x, len(lines))
        for line in lines:
            assert len(line) == y, "expected %d, actual %d %s" % (y, len(line), line)
        return ((x,y), lines)

def convertBoard(board):
    for (i, line) in enumerate(board):
        line = line.replace('.','0')
        line = line.replace('*','1')
        board[i] = [int(x) for x in line]
    return board

def revertBoard(board):
    for (i, line) in enumerate(board):
        line = ''.join([str(x) for x in line])
        line = line.replace('0','.')
        line = line.replace('1','*')
        board[i] = line
    return board

if __name__ == "__main__":
    (size, board) = readBoard(sys.argv[1])
    gens = int(sys.argv[2])
    board = convertBoard(board)
    life = Life(size, board)
    life.live(gens)
    board = revertBoard(life._board)
    print gens
    for row in board:
        print row
