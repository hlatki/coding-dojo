;; I totally borrowed some of these tests from mdelfino.  Thanks!
(ns life.core-test
  (:require [clojure.test :refer :all]
            [life.core :refer :all]
            [life.io :refer :all]))
(def live1 [[1 4] [2 3] [2 4]])

(def live2 [[0 0] [0 4] [0 5] [0 6] [0 7]
            [1 1]
            [2 1] [2 6] [2 7]
            [3 1] [3 6]])


(deftest does-it-work
  (testing "Testing that the next gen is what it's supposed to be"
    (is (= (game-to-str (next-gen live1 4 8) 4 8) "........\n...**...\n...**...\n........\n"))
    (is (= (game-to-str (next-gen live2 4 8) 4 8) ".....**.\n**......\n***...**\n......**\n"))))
    
