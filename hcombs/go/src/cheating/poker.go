/**
 * Created with IntelliJ IDEA.
 * User: hcombs
 * Date: 8/3/13
 * Time: 10:18 AM
 * To change this template use File | Settings | File Templates.
 */
package main

//import "fmt"

type HandRank uint8

const CARDS_IN_DECK = 52
const CARDS_IN_HAND = 5
const NUM_HAND_TYPES = 10

type Card uint32

type Deck [CARDS_IN_DECK]Card
type Hand [CARDS_IN_HAND]Card

const (
	_ HandRank = iota
	STRAIGHT_FLUSH HandRank = iota
	FOUR_OF_A_KIND HandRank = iota
	FULL_HOUSE HandRank = iota
	FLUSH HandRank = iota
	STRAIGHT HandRank = iota
	THREE_OF_A_KIND HandRank = iota
	TWO_PAIR HandRank = iota
	ONE_PAIR HandRank = iota
	HIGH_CARD HandRank = iota
)

var handRankStrings = [...]string {
	"",
	"Straight Flush",
	"Four of a Kind",
	"Full House",
	"Flush",
	"Straight",
	"Three of a Kind",
	"Two Pair",
	"One Pair",
	"High Card",
}

func (h HandRank) String() string { return handRankStrings[h] }

type Suit uint16
const (
	SPADE Suit =   1 << (iota + 12)
	HEART Suit =   1 << (iota + 12)
	DIAMOND Suit = 1 << (iota + 12)
	CLUB Suit =    1 << (iota + 12)
	NUM_SUITS = iota
)

const SUIT_MASK = 0xF000
const CARD_MASK = 0xFF
const RANK_MASK = 0xF

func (s Suit) String() string {
	switch s {
	case SPADE: return "S"
	case HEART: return "H"
	case CLUB: return "C"
	case DIAMOND: return "D"
	}
	return "?"
}

type CardRank uint8

const (
	DEUCE CardRank = iota
	TREY
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
	NUM_CARDS
)

var cardRankString = [NUM_CARDS]string{"2","3","4","5","6","7","8","9","T","J","Q","K","A",}


/*
** each of the thirteen card ranks has its own prime number
**
** deuce = 2
** trey  = 3
** four  = 5
** five  = 7
** ...
** king  = 37
** ace   = 41
*/
var primes = [...]uint { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41 };







