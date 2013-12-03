Poker in Go
===========
This implements the Kata using a brute force evaluation method + 
histogram in Go 1.1.

Running
=======
1. Download Go 1.1
2. grab the code
3. CD to the /src directory
4. type `make` (assumes the `go` toolchain is in your PATH)
5. Run the resultant 'poker' program like this:
   - `poker "User1: 2D 3C 4H 5S 6S  User2: 3D 4H 5S 6C 7H"`
   - Note: Quotes are significant, as is the double-space between users.

Notes
=====
There's a 'cheating' directory that demonstrates a much faster way of doing it using a go library that does some bitwise awesomeness.
