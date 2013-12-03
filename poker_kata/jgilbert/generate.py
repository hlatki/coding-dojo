#!/usr/bin/python

import sys
from random import shuffle

SUIT = 'CDHS'
RANK = '23456789TJQKA'

def generate (count):
    deck = [r+s for r in RANK for s in SUIT]
    for i in range(count):
        shuffle(deck)
        b = deck[0:10:2]
        w = deck[1:10:2]
        print 'Black: {}  White: {}'.format(" ".join(str(x) for x in b), " ".join(str(x) for x in w))

if __name__ == '__main__':
    count = 10
    if len(sys.argv) > 1:
        count = int(sys.argv[1])
    generate (count)
