/**
 * Created with IntelliJ IDEA.
 * User: hcombs
 * Date: 8/3/13
 * Time: 10:40 AM
 * To change this template use File | Settings | File Templates.
 */
package main

import "fmt"

//
//   This routine initializes the deck.  A deck of cards is
//   simply an integer array of length 52 (no jokers).  This
//   array is populated with each card, using the following
//   scheme:
//
//   An integer is made up of four bytes.  The high-order
//   bytes are used to hold the rank bit pattern, whereas
//   the low-order bytes hold the suit/rank/prime value
//   of the card.
//
//   +--------+--------+--------+--------+
//   |xxxbbbbb|bbbbbbbb|cdhsrrrr|xxpppppp|
//   +--------+--------+--------+--------+
//
//   p = prime number of rank (deuce=2,trey=3,four=5,five=7,...,ace=41)
//   r = rank of card (deuce=0,trey=1,four=2,five=3,...,ace=12)
//   cdhs = suit of card
//   b = bit turned on depending on rank of card
//
func init_deck( deck *Deck ) {

	suit := CLUB // (0x8000)

	n := 0 //index into the deck array

	for i := 0; i < NUM_SUITS; i++ {
		for  j := uint(0); j< uint(NUM_CARDS) ; j++ {
			deck[n] = Card(
				primes[j] | // 'p' in the above
				(j << 8 ) | // 'r' in the above
				uint(suit) | // 'c,d,h, or s' in the above
				(1 << (16+j) ) )//'b' in the above
			n++
		}
		suit >>= 1 //go to the 'next' suit
	}
}

func hand_rank( val int ) HandRank {
	switch {
		case val > 6185: return HIGH_CARD
		case val > 3325: return ONE_PAIR
		case val > 2467: return TWO_PAIR
		case val > 1609: return THREE_OF_A_KIND
		case val > 1599: return STRAIGHT
		case val > 322:  return FLUSH
		case val > 166:  return FULL_HOUSE
		case val > 10:   return FOUR_OF_A_KIND
	}
	return STRAIGHT_FLUSH
}

func (h Hand) print() {
	for i:=0 ; i < CARDS_IN_HAND; i++ {
		fmt.Print( h[i]," " )
	}
	fmt.Println()
}

func (c Card) String() string {
	rank := (c >> 8) & 0xF
	return fmt.Sprintf("%s%s", cardRankString[rank], Suit(c & SUIT_MASK) )
}
