/**
 * Created with IntelliJ IDEA.
 * User: hcombs
 * Date: 7/23/13
 * Time: 10:03 AM
 * To change this template use File | Settings | File Templates.
 */
package main

import (
	"unicode/utf8"
	"fmt"
	"strings"
	"sort"
)

type cardRank int8
const (
	TWO cardRank = iota
	THREE
	FOUR
	FIVE
	SIX
	SEVEN
	EIGHT
	NINE
	TEN
	JACK
	QUEEN
	KING
	ACE
	ERROR
)

type HandRank int8
const (
	HIGH_CARD HandRank = iota
	PAIR
	TWO_PAIR
	THREE_OF_A_KIND
	STRAIGHT
	FLUSH
	FULL_HOUSE
	FOUR_OF_A_KIND
	STRAIGHT_FLUSH
)

func (h *HandRank) name() string{
	var name string
	switch (*h) {
		case HIGH_CARD: name = "high card: "
		case PAIR: name = "pair: "
		case TWO_PAIR: name = "two pair"
		case THREE_OF_A_KIND: name = "three of a kind"
		case STRAIGHT: name = "straight"
		case FLUSH: name = "flush"
		case FULL_HOUSE: name = "full house"
		case FOUR_OF_A_KIND: name = "four of a kind"
		case STRAIGHT_FLUSH: name = "straight flush"
	}
	return name
}

func GetCardRank( s string ) cardRank {
	r,_ := utf8.DecodeRuneInString(s)
	switch (r) {
	case '2','3','4','5','6','7','8','9':
		return cardRank( r - '2' )
	case 'T': return TEN
	case 'J': return JACK
	case 'Q': return QUEEN
	case 'K': return KING
	case 'A': return ACE
	}
	return ERROR
}

func GetCardSuit( s string ) rune  {
	return []rune(s)[1]
}

type Card struct {
	text string
	rank cardRank
	suit rune
}

func (c *Card) String() string {
	return c.text
}

func NewCard(s string) Card {
	var card Card
	card.text = s
	card.rank = GetCardRank(s)
	card.suit = GetCardSuit(s)
	return card
}

type Cards []Card
func (c Cards) Less( i,j int ) bool {
	return c[i].rank < c[j].rank
}
func (c Cards) Len() int { return len(c) }
func (c Cards) Swap(i,j int) {
	c[j],c[i] = c[i], c[j]
}

func (c *Cards) String() string {
	return fmt.Sprintf("%s %s %s %s %s",
		(*c)[0].text,
		(*c)[1].text,
		(*c)[2].text,
		(*c)[3].text,
		(*c)[4].text)
}

func NewCards(s string) Cards {
	c := make(Cards, 5)
	for i, s := range strings.Split(s," ") {
		c[i] = NewCard(s)
	}
	sort.Sort( c )
	return c
}

type Hand struct {
	player string
	cards Cards
	rank HandRank
	victoryLap string
}

func NewHand( s string ) Hand {
	g := strings.Split(s, ": ")
	var game Hand
	game.player = g[0]
	game.cards = NewCards(g[1])
	game.rank = Rank(&game.cards)
	return game
}

func compareEqualHands ( l, r *Hand) *Hand {
	return nil
}

func (g *Hand) whoWon( otherGame *Hand ) *Hand {
	if (g.rank == otherGame.rank) {
		return compareEqualHands( g, otherGame )
	}

	if g.rank > otherGame.rank {
		return g
	} else {
		return otherGame
	}
}
