(ns conways-game.core-test
  (:require [clojure.test :refer :all]
            [conways-game.core :refer :all]))

(def test-inputs
  [".........\n....*....\n...***...\n....*....\n........."
   ".........\n....*....\n....*....\n....*....\n........."
   ".........\n.........\n...***...\n.........\n........."
   "....\n.**.\n.**.\n...."
   "**\n**"])

(def test-outputs
  [".........\n...***...\n...*.*...\n...***...\n........."
   ".........\n.........\n...***...\n.........\n........."
   ".........\n....*....\n....*....\n....*....\n........."
   "....\n.**.\n.**.\n...."
   "**\n**"])

(deftest good-patterns
  (doseq [t (range (count test-inputs))]
    (testing (str "Pattern " t)
      (is (=
           (vec-to-string
             (get-nth-position
               (convert-str-to-vec (nth test-inputs t)) 1))
           (nth test-outputs t))))))
