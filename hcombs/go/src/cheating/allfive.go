/**
 * Created with IntelliJ IDEA.
 * User: hcombs
 * Date: 8/3/13
 * Time: 10:17 AM
 * To change this template use File | Settings | File Templates.
 */
package main

import (
	"fmt"
)


func main() {

	var deck Deck
	var hand Hand
	var freq [NUM_HAND_TYPES]int

	var i,j int

	init_deck(&deck)

	for a:=0; a < (CARDS_IN_DECK - 4); a++ {
		hand[0] = deck[a]
		for b:=a+1; b < (CARDS_IN_DECK - 3); b++ {
			hand[1] = deck[b]
			for c:=b+1; c < (CARDS_IN_DECK - 2); c++ {
				hand[2] = deck[c]
				for d:=c+1; d < (CARDS_IN_DECK - 1); d++ {
					hand[3] = deck[d]
					for e:=d+1; e < CARDS_IN_DECK; e++ {
						hand[4] = deck[e]

						i = hand.eval()
						j = int(hand_rank(i))
						freq[j]++
					}
				}
			}
		}
	}

	for i = 1 ; i < NUM_HAND_TYPES ; i++ {
		fmt.Printf("%15s: %8d\n", handRankStrings[i], freq[i] )
	}


}

