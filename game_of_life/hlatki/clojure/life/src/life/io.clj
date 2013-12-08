;; These functions read grids from files and print out the state of a game.
;; Note that this implementation assumes that the only thing in a file is the
;; board (where * indicates a living cell).

(ns life.io)

;; ## Functions Convert file to vector of living cells



(defn live-cells-in-row
  "Return list of live cells in a row"
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
  "Take file where first line contains number of rows and cols
  and the rest is the game state.
  Return map like
  {:rows 4
   :cols 8
   :live-cells list-of-live-cells"
  [filename]
  (let
    [list-of-lines (clojure.string/split (slurp filename) #"\n")
     num-rows-and-cols (clojure.string/split (first list-of-lines) #" ")
     game-str (rest list-of-lines)]
      (loop [rows game-str
             i 0
             live-cells []]
        (if (empty? rows)
          {:rows (Integer. (first num-rows-and-cols))
           :cols (Integer. (second num-rows-and-cols))
           :live-cells live-cells}
          (recur (rest rows)
                 (inc i)
                 (concat live-cells (live-cells-in-row (first rows) i)))))))


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


;;(game-to-str (slurp-life-file "/Users/hannahatkinson/dev/coding-dojo/game_of_life/hlatki/clojure/life/src/life/1.in"))


;;(def game-state (slurp-life-file "/Users/hannahatkinson/dev/coding-dojo/game_of_life/hlatki/clojure/life/src/life/1.in"))

;;(game-to-str (:live-cells game-state) (:rows game-state) (:cols game-state))
