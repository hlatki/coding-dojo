(ns poker.core-test
  (:require [clojure.test :refer :all]
            [poker.core :refer :all]))


(defn get-rank
  "helper function to get rank of hand, given hand as string"
  [hand-string]
  (first (rank-hand hand-string)))

(deftest test-rank-hand
  (testing "Test that hands are classified correctly"
    (is (get-rank "TS JS QS KS AS") STRAIGHT_FLUSH)
    (is (get-rank "2D 2S 2H 2C KH") FOUR_OF_A_KIND)
    (is (get-rank "2D 2H 2S AH AS") FULL_HOUSE)
    (is (get-rank "2H 2S 2C AH AD") FULL_HOUSE)
    (is (get-rank "3S 3H 3D 4D 4S") FULL_HOUSE)
    (is (get-rank "AH TH 8H 6H JH") FLUSH)
    (is (get-rank "6H 7S 8H 9S TS") STRAIGHT)
    (is (get-rank "2D 2S 2H JC AH") THREE_OF_A_KIND)
    (is (get-rank "3H AC 3D AS KD") TWO_PAIR)
    (is (get-rank "AH KS AC TS 2H") PAIR)
    (is (get-rank "6H 2C QH 3S TH") HIGH_CARD)))


;; Most of these are Jerry's test cases -- thanks, Jerry!
(deftest test-compare-hands
  (testing "Test that hands are compared correctly"
    (is (compare-hands "TS JS QS KS AS" "3H AC 3D AS KD") "White wins")
    (is (compare-hands "3H AC 3D AS KD" "TS JS QS KS AS") "Black wins")
    (is (compare-hands "2H 2S 2C AH AD" "3S 3H 3D 4D 4S") "Black wins")
    (is (compare-hands "JD AH 8S TC 4D" "KH AD 3S 5S 2S") "Black wins")
    (is (compare-hands "JD JH 8S TC 4D" "KH AD 3S 5S 2S") "White wins")
    (is (compare-hands "JD 7H 8S TC 4D" "KH AD 2H 5S 2S") "Black wins")
    (is (compare-hands "JD JH 8S TC 4D" "JS JC TS KS 8D") "Black wins")
    (is (compare-hands "2D 2H 3S 3H AD" "2S 2C 6D 6C KH") "Black wins")
    (is (compare-hands "2D 2H AS AH TD" "QS QC KD KC AS") "White wins")
    (is (compare-hands "9H 9S 9C 9D 2D" "8H 8S 8D 8C AS") "White wins")
    (is (compare-hands "AD AC AS 9H 2D" "KD KS KH AH QD") "White wins")))
