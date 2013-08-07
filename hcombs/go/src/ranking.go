/**
 * Created with IntelliJ IDEA.
 * User: hcombs
 * Date: 7/23/13
 * Time: 10:06 AM
 * To change this template use File | Settings | File Templates.
 */
package main

import (
	"sort"
	//"fmt"
)

//Define a histogram for checking card frequency
type histogram map[cardRank]Cards

func HistogramFrom( c *Cards ) *histogram {
	hist := histogram{}

	for _,card := range *c {
		hist[card.rank] = append( hist[card.rank], card )
	}
	return &hist
}

func (h histogram) distribution() [5]int {
	distribution := []int{}

	for _,v := range h {
		distribution = append(distribution, len(v))
	}

	sort.Ints(distribution)

	d := [...]int {0,0,0,0,0}
	i := 5-len(distribution)
	for _,v := range distribution {
		d[i] = v
		i+=1
	}

	return d
}

func (h histogram) getCardsByFrequency(freq int) []*Cards {
	c := []*Cards{}

	for _,v := range h {
		if (len(v) == freq) {
			c = append(c, &v)
		}
	}
	return c
}

func (h histogram) filterByLength( predicate func(i int) bool ) Cards {
	cards := Cards{}
	for _,v := range h {
		if predicate( len(v) ) {
			cards = append(cards,v[0])
		}
	}
	sort.Sort(sort.Reverse(cards))
	return cards
}

func (h histogram) getSingleCards() Cards {
    return h.filterByLength( func(i int) bool { return i == 1 } )
}

func (h histogram) getPairs() Cards {
	return h.filterByLength( func(i int) bool { return i == 2 } )
}

/**
* Rank equivalent hands based upon appropriate
* algorithms
 */
func rankEquivalentHands( h1, h2 *Hand ) *Hand {
	switch h1.rank {
		case STRAIGHT_FLUSH, STRAIGHT, HIGH_CARD, FLUSH: return rankHighCard(h1,h2)
	    case FOUR_OF_A_KIND: return rankFourOfAKind(h1,h2)
		case FULL_HOUSE: return rankFullHouse(h1,h2)
		case THREE_OF_A_KIND: return rankThreeOfAKind(h1,h2)
		case TWO_PAIR: return rankTwoPair(h1,h2)
		case ONE_PAIR: return rankPair(h1,h2)
	}
	return nil
}

func rankStraight( h1, h2 *Hand) *Hand {
	c1 := h1.hist.getSingleCards()[0]
	c2 := h1.hist.getSingleCards()[0]

	switch {
		case c1.rank > c2.rank: return h1
		case c1.rank < c2.rank: return h2
	}

	return nil;
}

func rankFourOfAKind( h1, h2 *Hand) *Hand {
	return rankByFrequency(h1, h2, 4)
}

func rankFullHouse(h1, h2 *Hand ) *Hand {
	winner := rankByFrequency(h1, h2, 3)
	if nil == winner {
		winner = rankByFrequency(h1,h2, 2)
	}
	return winner
}

/**
* Return the winning hand based upon a
* High Card algorithm.
*/
func rankHighCard(h1,h2 *Hand ) *Hand {

	//getSingleCards returns a reverse sorted array of Card
	//structs for each card in the histogram that occurs once.

	c1 := h1.hist.getSingleCards()
	c2 := h2.hist.getSingleCards()

	for i:=0; i < len(c1) ;  i++ {
		switch {
			case c1[i].rank > c2[i].rank: return h1
			case c2[i].rank > c1[i].rank: return h2
		}
	}
	return nil //Tie;
}

func rankThreeOfAKind(h1, h2 *Hand) *Hand {
	winner := rankByFrequency(h1, h2, 3)
	if nil == winner {
		winner = rankHighCard(h1, h2);
	}
	return winner
}

func rankPair(h1,h2 *Hand) *Hand {
	winner := rankByFrequency(h1,h2, 2)
	if nil == winner {
		winner = rankHighCard(h1,h2)
	}
	return winner
}

func rankTwoPair(h1,h2 *Hand) *Hand {
	c1 := h1.hist.getPairs()
	c2 := h2.hist.getPairs()

	for i:=0; i < len(c1);i++ {
		switch {
			case c1[i].rank > c2[i].rank: return h1
			case c2[i].rank > c1[i].rank: return h2
		}
	}
	return rankHighCard(h1,h2)
}


func rankByFrequency(h1, h2 *Hand, freq int) *Hand {
	cards1 := h1.hist.getCardsByFrequency(freq)
	cards2 := h2.hist.getCardsByFrequency(freq)

	switch {
		case (*cards1[0])[0].rank > (*cards2[0])[0].rank: return h1
		case (*cards1[0])[0].rank < (*cards2[0])[0].rank: return h2
	}

	return nil
}


// implements the algorithm described here
//
// http://nsayer.blogspot.com/2007/07/algorithm-for-evaluating-poker-hands.html
func Rank(c *Hand) {
    c.hist = HistogramFrom( &c.cards )
	c.rank = HIGH_CARD

	switch ( c.hist.distribution() ) {
		case [5]int{0,0,0,1,4}: c.rank = FOUR_OF_A_KIND
		case [5]int{0,0,0,2,3}: c.rank = FULL_HOUSE
		case [5]int{0,0,1,1,3}: c.rank = THREE_OF_A_KIND
		case [5]int{0,0,1,2,2}: c.rank = TWO_PAIR
		case [5]int{0,1,1,1,2}: c.rank = ONE_PAIR
	}

	if (c.rank == HIGH_CARD) {
		//couldn't get the rank based on histogram
		flush := isFlush( &c.cards)
		straight := isStraight( &c.cards )

		switch {
			case flush && straight : c.rank = STRAIGHT_FLUSH
			case flush: c.rank = FLUSH
			case straight: c.rank = STRAIGHT
			default: c.rank = HIGH_CARD
		}
	}
}

func isFlush( g *Cards ) bool {
	suit := (*g)[0].suit
	for i:=1; i < len(*g); i++ {
		if ((*g)[i]).suit != suit {
			return false
		}
	}
	return true
}

func isStraight( g *Cards ) bool {
	return ((*g)[4].rank - (*g)[0].rank) == 4
}


