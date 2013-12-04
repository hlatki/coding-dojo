/**
 * Created with IntelliJ IDEA.
 * User: hcombs
 * Date: 7/31/13
 * Time: 3:55 PM
 * To change this template use File | Settings | File Templates.
 */
package main

import (
	"testing"
	"fmt"
)

var validSuits = []struct {
	s suit
	value uint
} {
	{ SPADE, 0x1000 },
	{ HEART, 0x2000 },
	{ DIAMOND, 0x4000 },
	{ CLUB, 0x8000 },
}


func Test_suits(t *testing.T) {

  for _,testCase := range validSuits {
    if (testCase.s != suit(testCase.value) ) {
		t.Errorf("Expected %v got %v", testCase.value, testCase.s)
	}
  }
}

var validCards = []struct{
	c cardRank
	s string
}{
	{TWO, "2"},
	{THREE, "3"},
	{FOUR, "4"},
	{FIVE, "5"},
	{SIX, "6"},
	{SEVEN, "7"},
	{EIGHT, "8"},
	{NINE, "9"},
	{TEN, "T"},
	{JACK, "J"},
	{QUEEN, "Q"},
	{KING, "K"},
	{ACE, "A"},
}

func Test_cards( t *testing.T) {
	for _,testCase := range validCards {

		rank := GetCardRank(testCase.s)

		//check that we decode the string correctly
		if ( testCase.c != rank ) {
			t.Errorf( "expected %s, got %s", testCase.c, rank)
		}

		str := fmt.Sprintf("%v", testCase.c)
		//check we can encode the rank correctly
		if (testCase.s != str ) {
			t.Errorf( "expected %s, got %s", testCase.s, str)
		}

	}
}

var histograms = []struct {
   cardString string
   distribution [5]int
} {
	{"2C 2S 2H 2D AS", [5]int{0,0,0,1,4} },
	{"2C 3C 4C 5C 6C", [5]int{1,1,1,1,1} },
}

func Test_histogram( t *testing.T ) {

	for _, testCase := range histograms {

		cards := NewCards(testCase.cardString)
		h := HistogramFrom( &cards )

		dist := h.distribution()
		if  testCase.distribution != dist {
			t.Errorf("expected %s, got %s", testCase.distribution, dist)
		}
	}

}

