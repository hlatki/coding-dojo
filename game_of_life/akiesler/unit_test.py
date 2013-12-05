#!/usr/bin/env python
from poc import TemplateTestCase, Call, template
from life import *
import unittest

class TestLife(unittest.TestCase):
    __metaclass__ = TemplateTestCase

    test_cases = {
        "beacon": Call("testcases/beacon", 1, "testcases/beacon1"),
        "beehive": Call("testcases/beehive", 1, "testcases/beehive"),
        "blinker": Call("testcases/blinker", 1, "testcases/blinker1"),
        "block": Call("testcases/block", 1, "testcases/block."),
        "boat": Call("testcases/boat", 1, "testcases/boat"),
        "example": Call("testcases/example", 1, "testcases/example1"),
        "loaf": Call("testcases/loaf", 1, "testcases/loaf"),
        "toad": Call("testcases/toad", 1, "testcases/toad1"),
        "pulsar1": Call("testcases/pulsar", 1, "testcases/pulsar1"),
        "pulsar2": Call("testcases/pulsar", 2, "testcases/pulsar2")
    }

    @template(test_cases)
    def _test_frames(self, test, gens, soln):
        (size, board) = readBoard(test)
        board = convertBoard(board)
        life = Life(size, board)
        life.live(gens)
        board = revertBoard(life._board)
        (soln_size, soln_board) = readBoard(soln)
        assert size == soln_size, "actual: %s, expected: %s" % (size, soln_size)
        for (actual, expected) in zip(board, soln_board):
            assert actual == expected, "actual: %s, expected: %s" % (actual, expected)

if __name__ == '__main__':
    unittest.main()
