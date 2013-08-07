/**
 * Created with IntelliJ IDEA.
 * User: hcombs
 * Date: 7/22/13
 * Time: 12:34 PM
 * To change this template use File | Settings | File Templates.
 */
package main

import(
  "fmt"
  "os"
  "strings"
)


func main() {
	games := strings.Split( os.Args[1], "  ")
	g1 := NewHand(games[0])
	g2 := NewHand(games[1])

	winner := g1.whoWon(&g2)
	if (nil == winner) {
		fmt.Println("Tie.")
	} else {
		fmt.Println(printWinner( winner ))
	}
}


