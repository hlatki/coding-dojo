# conways-game

A Clojure implementation of the coding kata found [here][1].

  [1]: http://codingdojo.org/cgi-bin/wiki.pl?KataGameOfLife


## Usage

There are currently two ways to interact with this program.

1. Invoking `lein run` will run the code in main.clj, which is a loop taking
   the input specified in the above link and returning the next game of life
   position.

2. Using the ClojureScript build available [here][2]. This is an interactive,
   fixed size board that you can toggle the cells and compute the next
   position.

  [2]: http://jprof.github.io/conways-game-of-life-clj/

## License

Copyright © 2013 Justin Proffitt

Distributed under the Eclipse Public License either version 1.0 or (at
your option) any later version.
