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
	"runtime"
	"flag"
	"runtime/pprof"
	"os"
	"log"

	"github.com/miniharryc/poker"
)

type HandFrequency [poker.NUM_HAND_TYPES]int

// Check a subslice of hands, starting with 'intiial' and incrementing by
// step, trying each combination below that.
func checkHands( deck_ *poker.Deck, initial, step int, out chan HandFrequency ) {

	var hand poker.Hand
	deck := *deck_
	var frequency HandFrequency

	for a:=initial; a < (poker.CARDS_IN_DECK - 4); a+=step {
		hand[0] = deck[a]
		for b:=a+1; b < (poker.CARDS_IN_DECK - 3); b++ {
			hand[1] = deck[b]
			for c:=b+1; c < (poker.CARDS_IN_DECK - 2); c++ {
				hand[2] = deck[c]
				for d:=c+1; d < (poker.CARDS_IN_DECK - 1); d++ {
					hand[3] = deck[d]
					for e:=d+1; e < poker.CARDS_IN_DECK; e++ {
						hand[4] = deck[e]
						frequency[ hand.Eval().Rank() ]++
					}
				}
			}
		}
	}

	//send result to the output channel
	out <- frequency
}

var parallels = flag.Int("p", 1, "number of parallel processes")
var cpuprofile = flag.String("cpuprofile", "", "write cpu profile to file")

func main() {

	var freq HandFrequency

	deck := poker.NewDeck();

	flag.Parse()

	if *cpuprofile != "" {
		f, err := os.Create(*cpuprofile)
		if err != nil {
			log.Fatal(err)
		}
		pprof.StartCPUProfile(f)
		defer pprof.StopCPUProfile()
	}

	runtime.GOMAXPROCS(*parallels)

	out := make( chan HandFrequency )

	for i:=0; i < *parallels; i++ {
		go checkHands( deck, i, *parallels, out )
	}

	//read the results
	var f1 HandFrequency
	for i:=0; i < *parallels; i++ {
		f1 = <- out //read the result
		for i, val := range f1 {
			freq[i] += val
		}
	}

	close(out)

	for i := 1 ; i < poker.NUM_HAND_TYPES ; i++ {
		fmt.Printf("%15s: %8d\n", poker.HandRank(i), freq[i] )
	}


}

