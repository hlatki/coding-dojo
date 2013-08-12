#!/usr/bin/python

import sys
from random import shuffle

RANK = '23456789TJQKA'
SUIT = 'CDHS'

class Hand:
    UNKNOWN = -1 
    HIGH_CARD = 0
    ONE_PAIR = 1
    TWO_PAIR = 2
    THREE_OF_A_KIND = 3
    STRAIGHT = 4
    FLUSH = 5
    FULL_HOUSE = 6
    FOUR_OF_A_KIND = 7
    STRAIGHT_FLUSH = 8

    def __init__(self, name, cards):
        self.cards = cards
        self.name = name
        self.rank = self.UNKNOWN
        self.top_rank = '2'
        self.bottom_rank = '2'
        if self.is_flush() and self.is_straight():
            self.rank = self.STRAIGHT_FLUSH
            #print "{} has a Straight-flush {}-high".format(self.name, self.top_rank)
        elif self.is_4ok():
            #print "{} has a four-of-a-kind {}-high".format(self.name, self.top_rank)
            self.rank = self.FOUR_OF_A_KIND
        elif self.has_3ok() and self.has_pair():
            #print "{} has a full house {}'s full of {}'s".format(self.name, self.top_rank, self.bottom_rank)
            self.rank = self.FULL_HOUSE
        elif self.is_flush():
            #print "{} has a Flush {}-high".format(self.name, self.top_rank)
            self.rank = self.FLUSH
        elif self.is_straight():
            #print "{} has a Straight {}-high".format(self.name, self.top_rank)
            self.rank = self.STRAIGHT
        elif self.has_3ok():
            #print "{} has a three-of-a-kind {}-high".format(self.name, self.top_rank)
            self.rank = self.THREE_OF_A_KIND
        elif self.has_two_pair():
            #print "{} has two-pair {}'s and {}'s".format(self.name, self.top_rank, self.bottom_rank)
            self.rank = self.TWO_PAIR
        elif self.has_pair():
            #print "{} has a pair {}'s".format(self.name, self.bottom_rank)
            self.rank = self.ONE_PAIR
        else:
            self.rank = self.HIGH_CARD

    def is_flush(self):
        h = self.cards
        if h[0][1] == h[1][1] and h[1][1] == h[2][1] and h[2][1] == h[3][1] and h[3][1] == h[4][1]:
            self.top_rank = h[0][0]
            return True
        else:
            return False

    def is_straight(self):
        h = self.cards
        if (RANK.index(h[0][0]) - 1) != RANK.index(h[1][0]):
            return False
        elif (RANK.index(h[1][0]) - 1) != RANK.index(h[2][0]):
            return False
        elif (RANK.index(h[2][0]) - 1) != RANK.index(h[3][0]):
            return False
        elif (RANK.index(h[3][0]) - 1) != RANK.index(h[4][0]):
            return False
        else:
            self.top_rank = h[0][0]
            return True

    def is_4ok(self):
        h = self.cards
        if h[0][0] == h[1][0] and h[1][0] == h[2][0] and h[2][0] == h[3][0]:
            self.top_rank = h[0][0]
            return True
        elif h[1][0] == h[2][0] and h[2][0] == h[3][0] and h[3][0] == h[4][0]:
            self.top_rank = h[1][0]
            return True
        else:
            return False

    def has_3ok(self):
        h = self.cards
        if h[0][0] == h[1][0] and h[1][0] == h[2][0] and h[2][0] != h[3][0]:
            self.top_rank = h[0][0]
            return True
        elif h[0][0] != h[1][0] and h[1][0] == h[2][0] and h[2][0] == h[3][0] and h[3][0] != h[4][0]:
            self.top_rank = h[1][0]
            return True
        elif h[1][0] != h[2][0] and h[2][0] == h[3][0] and h[3][0] == h[4][0]:
            self.top_rank = h[2][0]
            return True
        else:
            return False

    def has_two_pair(self):
        h = self.cards
        if h[0][0] == h[1][0] and h[1][0] != h[2][0] and h[2][0] == h[3][0] and h[3][0] != h[4][0]:
            self.top_rank = h[0][0]
            self.bottom_rank = h[2][0]
            return True
        elif h[0][0] == h[1][0] and h[1][0] != h[2][0] and h[2][0] != h[3][0] and h[3][0] == h[4][0]:
            self.top_rank = h[0][0]
            self.bottom_rank = h[3][0]
            return True
        elif h[0][0] != h[1][0] and h[1][0] == h[2][0] and h[2][0] != h[3][0] and h[3][0] == h[4][0]:
            self.top_rank = h[1][0]
            self.bottom_rank = h[3][0]
            return True
        else:
            return False

    def has_pair(self):
        # NOTE: only setting bottom_rank on pair for full-house case
        h = self.cards
        if h[0][0] == h[1][0] and h[1][0] != h[2][0]:
            self.bottom_rank = h[0][0]
            return True
        elif h[0][0] != h[1][0] and h[1][0] == h[2][0] and h[2][0] != h[3][0]: 
            self.bottom_rank = h[1][0]
            return True
        elif h[1][0] != h[2][0] and h[2][0] == h[3][0] and h[3][0] != h[4][0]: 
            self.bottom_rank = h[2][0]
            return True
        elif h[2][0] != h[3][0] and h[3][0] == h[4][0]:
            self.bottom_rank = h[3][0]
            return True
        else:
            return False

    def __cmp__(self, other):
        if self.rank != other.rank:
            return self.rank - other.rank
        else:
            # Find first unique card
            if self.rank == self.HIGH_CARD:
                if RANK.index(self.cards[0][0]) == RANK.index(other.cards[0][0]):
                    if RANK.index(self.cards[1][0]) == RANK.index(other.cards[1][0]):
                        if RANK.index(self.cards[2][0]) == RANK.index(other.cards[2][0]):
                            if RANK.index(self.cards[3][0]) == RANK.index(other.cards[3][0]):
                                if RANK.index(self.cards[4][0]) == RANK.index(other.cards[4][0]):
                                    return 0
                                else:
                                    return RANK.index(self.cards[4][0]) - RANK.index(other.cards[4][0])
                            else:
                                return RANK.index(self.cards[3][0]) - RANK.index(other.cards[3][0])
                        else:
                            return RANK.index(self.cards[2][0]) - RANK.index(other.cards[2][0])
                    else:
                        return RANK.index(self.cards[1][0]) - RANK.index(other.cards[1][0])
                else:
                    return RANK.index(self.cards[0][0]) - RANK.index(other.cards[0][0])
            # Not high-card, check pair rank
            if self.rank == self.ONE_PAIR:
                # TODO: Check kicker
                return RANK.index(self.bottom_rank) - RANK.index(other.bottom_rank)
            elif self.top_rank == other.top_rank:
                if self.bottom_rank == self.bottom_rank:
                    # TODO: Check kickers and flush rank
                    return 0
                else:
                    return RANK.index(self.bottom_rank) - RANK.index(other.bottom_rank)
            else:
                return RANK.index(self.top_rank) - RANK.index(other.top_rank)

    def to_str(self):
        if self.rank == self.UNKNOWN:
            return "UNKNOWN"
        elif self.rank == self.HIGH_CARD:
            return "High card {}".format(self.cards[0][0])
        elif self.rank == self.ONE_PAIR:
            return "One pair {}'s".format(self.bottom_rank)
        elif self.rank == self.TWO_PAIR:
            return "Two pair {}'s and {}'s".format(self.top_rank, self.bottom_rank)
        elif self.rank == self.THREE_OF_A_KIND:
            return "Three of kind {}'s".format(self.top_rank)
        elif self.rank == self.STRAIGHT:
            return "Straight {}-high".format(self.top_rank)
        elif self.rank == self.FLUSH:
            return "Flush {}-high".format(self.top_rank)
        elif self.rank == self.FULL_HOUSE:
            return "Full House {}'s full of {}'s".format(self.top_rank, self.bottom_rank)
        elif self.rank == self.FOUR_OF_A_KIND:
            return "Four of a kind {}'s".format(self.top_rank)
        elif self.rank == self.STRAIGHT_FLUSH:
            return "Straight Flush {}-high".format(self.top_rank)
        else:
            # TODO: Raise error?
            return ""


def key_cmp(card):
    return RANK.index(card[0]), SUIT.index(card[1])

def parse_line_to_hands(line):
    fields = line.split()
    # fields[0] is the player 1 name, fields[6] is the player 2 name
    return Hand(fields[0], sorted(fields[1:6], key=key_cmp, reverse=True)), Hand(fields[6], sorted(fields[7:], key=key_cmp, reverse=True))

def print_results(winner=None, loser=None):
    if winner:
        print '{:<10}: {} : Winner with {}'.format(winner.name, " ".join(str(x) for x in winner.cards), winner.to_str())
    if loser:
        print '{:<10}: {} : {}'.format(loser.name, " ".join(str(x) for x in loser.cards), loser.to_str())

def analyze_hand(line):
    #print 'Analyzing "%s"' % line.rstrip()
    player = parse_line_to_hands(line)
    if player[0] == player[1]:
            print_results(winner=player[0])
            print_results(winner=player[1])
    elif player[0] > player[1]:
        print_results(winner=player[0], loser=player[1])
    else:
        print_results(winner=player[1], loser=player[0])

if __name__ == '__main__':
    f = sys.stdin
    if len(sys.argv) > 1:
        # open data file
        f = open(sys.argv[1], 'r')

    for line in f:
        analyze_hand(line)
        print
