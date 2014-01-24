(ns sum-sequences.core-test
  (:require [clojure.test :refer :all]
            [sum-sequences.core :refer :all]
            [sum-sequences.gen :refer :all]))
(def sum-seq-in [1 1 2 3 7])
(def sum-seq-result '([1 1] [1 1 2] [1 1 2 3 7] [1 2 3]))

(deftest simple-sum-seq
  (testing "Can it find some sum seqs"
    (is (= (recur-naive-get-all-sum-seqs sum-seq-in) sum-seq-result))))
