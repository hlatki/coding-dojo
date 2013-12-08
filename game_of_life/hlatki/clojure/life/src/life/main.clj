;; to run:
;; lein run input-file-name num-of-generations-to-run
;; note that in valid input files the first line consists of the number of rows
;; and columns (space deliminated) and that subsequent lines contain the state of
;; the board. * indicates a living cell, and . a dead cell.
;;

(ns life.main
  (:require [life.core :as life]
            [life.io]))


;; Generation 0 is the initial state from the file
(defn -main
  [& args]
  (let [initial-game-state (life.io/slurp-life-file (first args))
        rows (:rows initial-game-state)
        cols (:cols initial-game-state)
        gens-to-run (Integer. (second args))]
    (loop [i 1
           current-state (:live-cells initial-game-state)]
      (if (> i gens-to-run)
        "Done!"
        (do 
          (println (str "Generation " i " :")) 
          (println (life.io/game-to-str current-state rows cols))
          (recur (inc i)
                 (life/next-gen current-state rows cols)))))))


