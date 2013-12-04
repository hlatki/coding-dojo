(ns poker.helper-test
  (:require [clojure.test :refer :all]
            [poker.helper :refer :all]))

;; ## Tests for consecutive? function
(deftest test-sorted-consecutive
  (testing "Testing sorted consecutive sequences")
  (consecutive? (sort > [1 2 3 4 5 6]))
  (consecutive? (sort > [1 2 3 4 5 6]))
  (consecutive? #{7 6 5 4 3})
  (consecutive? '(8 7 6 5 4 3 2 1 0)))
(deftest test-unsorted-consecutive
  (testing "Testing unsorted sequences that are consecutive")
  (consecutive? (into (sorted-set) [1 4 2 3 5]))
  (consecutive? (into (sorted-set) [1 3 2 0 4])))
(deftest test-unsorted-nonconsecutive
  (testing "Testing unsorted sequences that are not consecutive")
  (not (consecutive? [5 7 3 4 1]))
  (not (consecutive? [-5 -2 -3 -4 -9])))

;; ## Tests for all-same-suit
(deftest test-all-same-suit
  (testing "Testing all same suit")
  (all-same-suit? ["C" "C" "C" "C" "C"])
  (not (all-same-suit? ["C" "C" "D" "C" "C"])))


;; ## Tests for n-of-a-kind
(deftest test-two-n-of-a-kind
  (testing "Testing n-of-a-kind with n of 2")
  (is (n-of-a-kind 2 [5,5,6,8,4]) [5 2])
  (is (n-of-a-kind 2 [5,5,6,4,4]) [4 2 5 2])
  (empty? (n-of-a-kind 2 [5,9,6,1,4])))

(deftest test-four-of-a-kind
  (testing "Testing four-of-a-kind")
  (four-of-a-kind? [7 2 2 2 2])
  (not (four-of-a-kind? [7 5 2 1 2])))

(deftest test-three-of-a-kind
  (testing "Testing three-of-a-kind")
  (three-of-a-kind? [7 2 2 8 2])
  (not (three-of-a-kind? [7 5 2 1 2])))

(deftest test-pairs
  (testing "Testing pairs")
  (is (pairs [5,5,7,7,2]) '([5 2],[7,2])))

(deftest test-two-pair
  (testing "Testing two-pairs")
  (two-pair? [5 5 7 7 1])
  (not (two-pair? [5 5 7 7 1 1]))
  (two-pair? [5 6 7 7 1]))
