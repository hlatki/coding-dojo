;; These functions read grids from files and print out the state of a game.
;; Note that this implementation assumes that the only thing in a file is the
;; board (where * indicates a living cell).

(ns life.io)

;; ## Functions Convert file to vector of living cells

(defn list-of-lines-in-file
  "Return list where each element is a line from the file"
  [filename]
  (clojure.string/split (slurp filename) #"\n"))
(defn live-cells-in-row
  [row row-num]
  (loop [cells (seq row)
         i 0
         live-cells []]
    (if (not (seq cells))
      live-cells
      (recur (rest cells)
             (inc i)
             (if (= (first cells) \*)
               (conj live-cells [row-num i])
               live-cells)))))

(defn slurp-life-file
  "Call this function to slurp a file and get back a list of live cells.
  Get a list of live cells in a file that contains a grid like:
  *...****
  .*......
  .*....**
  .*....*.
  "
  [filename]
  (loop [cells (list-of-lines-in-file filename)
         i 0
         live-cells []]
    (if (empty? cells)
      live-cells
      (recur (rest cells)
             (inc i)
             (concat live-cells (live-cells-in-row (first cells) i))))))




;; ## Functions to output game state

(defn all-cells-in-order
  "Generate list of all possible cells in order"
  [rows cols]
   (partition cols (doall
     (for [i (range rows)
       j (range cols)]
       [i j]))))

;; move this into core
(defn is-alive?
  [alive-cells cell]
  (some #{cell} alive-cells))


(defn row-of-cells-to-str
  "Take a list of cells and convert to string (look up each cell in
  alive-cells to see if it's alive"
  [row alive-cells]
  (reduce
    (fn
      [str-row elem]
      (if (is-alive? alive-cells elem)
        (str str-row "*")
        (str str-row ".")))
     ""
     row))

(defn game-to-str
  "Take a list of living cells and the number of rows and columns and output the
  string representation of game state.  This is the one to call."
  [alive-cells rows cols]
  (reduce
    (fn
      [output row]
      (str output (row-of-cells-to-str row alive-cells) "\n"))
     ""
     (all-cells-in-order rows cols)))


(game-to-str (slurp-life-file "/Users/hannahatkinson/dev/coding-dojo/game_of_life/hlatki/clojure/life/src/life/1.in") 4 8)




