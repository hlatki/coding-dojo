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
type histogram map[cardRank][]Card

func HistogramFrom( c *Cards ) *histogram {
	hist := histogram{}

	for _,card := range *c {
		hist[card.rank] = append( hist[card.rank], card )
	}
	return &hist
}

func (h *histogram) distribution() [5]int {
	distribution := []int{}

	for _,v := range *h {
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

// implements the algorithm described here
//
// http://nsayer.blogspot.com/2007/07/algorithm-for-evaluating-poker-hands.html
func Rank(c *Cards) HandRank {
    hist := HistogramFrom( c )

	rank := HIGH_CARD

	//dist := hist.distribution()
	//fmt.Println(dist)

	switch ( hist.distribution() ) {
		case [5]int{0,0,0,1,4}: rank = FOUR_OF_A_KIND
		case [5]int{0,0,0,2,3}: rank = FULL_HOUSE
		case [5]int{0,0,1,1,3}: rank = THREE_OF_A_KIND
		case [5]int{0,0,1,2,2}: rank = TWO_PAIR
		case [5]int{0,1,1,1,2}: rank = PAIR
	}

	if (rank == HIGH_CARD) {
		//couldn't get the rank based on histogram
		flush := isFlush( c )
		straight := isStraight( c )

		switch {
			case flush && straight : rank = STRAIGHT_FLUSH
			case flush: rank = FLUSH
			case straight: rank = STRAIGHT
			default: rank = HIGH_CARD
		}
	}

	//fmt.Println(rank)

	return rank
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


