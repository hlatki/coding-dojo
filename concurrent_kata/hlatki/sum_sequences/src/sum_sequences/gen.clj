;; Generate stuff to parse
(ns sum-sequences.gen)

(def sample-sequence [1 1 2 3 7])

(defn generate-seq
  "Generate vector of n radom numbers in range [1,9]"
  [n]
  (loop [i 0
         s []]
    (if (= i n)
      s
      (recur (inc i) (conj s (inc (rand-int 9)))))))

(defn generate-seq-str
  "Generate string of n radom numbers in range [1,9]"
  [n]
  (loop [i 0
         s ""]
    (if (= i n)
      s
      (recur (inc i) (str s (inc (rand-int 9)))))))

(defn generate-lazy-seq
  [n]
  (take n (repeatedly #(inc (rand-int 9)))))


(generate-lazy-seq 100)
(generate-seq 1000)
