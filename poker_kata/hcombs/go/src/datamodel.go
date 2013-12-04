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

type suit uint
const (
	SPADE suit =   1 << (iota + 12)
	HEART suit =   1 << (iota + 12)
	DIAMOND suit = 1 << (iota + 12)
	CLUB suit =    1 << (iota + 12)
	UNKNOWN_SUIT
)

func suitFromString(s string) suit {
	r,_ := utf8.DecodeLastRuneInString(s)

	switch r {
		case 'S': return SPADE
		case 'H': return HEART
		case 'C': return CLUB
		case 'D': return DIAMOND
	}
	return UNKNOWN_SUIT
}

func (s suit) String() string {
	switch s {
		case SPADE: return "S"
		case HEART: return "H"
		case CLUB: return "C"
		case DIAMOND: return "D"
	}
	return "?"
}


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

// Prime #'s that let you "score" a hand without sorting it
var cardPrimes = [...]int {
	2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41,
}

var cardRankString = [...]string {
  "2","3","4","5","6","7","8","9","T","J","Q","K","A",
}

func (c cardRank) String() string {
	return cardRankString[c]
}

type HandRank int8
const (
	_ HandRank= iota
	STRAIGHT_FLUSH
	FOUR_OF_A_KIND
	FULL_HOUSE
	FLUSH
	STRAIGHT
	THREE_OF_A_KIND
	TWO_PAIR
	ONE_PAIR
	HIGH_CARD
)

var handRankString = [...]string { "",
  "Stright Flush", "Four of a Kind", "Full House", "Flush", "Straight",
  "Three of a Kind", "Two Pair", " One Pair", "High Card",
}

func (h HandRank) String() string {
	return handRankString[h]
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
	rank cardRank
	suit rune
}

func (c Card) String() string {
	return fmt.Sprintf("%v%s", c.rank, string(c.suit) )
}

func NewCard(s string) Card {
	var card Card
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

/*func (c Cards) String() string {
	return fmt.Sprintf("%s %s %s %s %s",
		c[0],
		c[1],
		c[2],
		c[3],
		c[4])
}
*/

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
	hist *histogram
	equalityComparison func(l,r *Hand) *Hand
}

func NewHand( s string ) Hand {
	g := strings.Split(s, ": ")
	var game Hand
	game.player = g[0]
	game.cards = NewCards(g[1])
	Rank(&game)
	return game
}

func printWinner( g *Hand ) string {
	return fmt.Sprintf("%s wins. - with %s\n", g.player, g.rank )
}


func (g *Hand) whoWon( otherGame *Hand ) *Hand {

	var winner *Hand

	if (g.rank == otherGame.rank) {
		return rankEquivalentHands(g, otherGame)
	} else {
		winner = otherGame
		if g.rank < otherGame.rank {
			winner = g
		}
	}

	return winner
}
