(ns sum-sequences.core)


(defn does-sum?
  "Is the sum of first i elements of vector v equal to the ith element of v?"
  [v i]
  (= (apply + (take i v)) (nth v i)))

(defn alt-does-sum?
  "alternate does-sum to maybe use"
  [v]
  (= (apply + (take (dec (count v)) v))
     (last v)))


;; ## Naive approach
(defn pretty-get-seqs-from-first
  "Given vector v, where each element is a number in range [1,9], return all sequences
  where the sum of the ith through i+n elements equals the i+n+1 element. For example, [1 1 2 3 7] would return
  [[1] [1 1] [1 1 2] [1 2 3] [1 1 2 3 7]]"
  [v]
  (filter #(alt-does-sum? %)
          (map #(vec (take % v)) (range 1 (inc (count v)))))) ;;range is [start end) so increment to compensate



(defn recur-naive-get-all-sum-seqs
  "Given vector v, where each element is a number in range [1,9], return all sequences
  where the sum of the ith through i+n elements equals the i+n+1 element. For example, [1 1 2 3 7] would return
  [[1] [1 1] [1 1 2] [1 2 3] [1 1 2 3 7]]"
  [v]
  (letfn [(seqs-from-i [curr-vec acc-seqs]
                       (if (not (seq curr-vec))
                         acc-seqs
                         ;;(recur (vec (rest curr-vec)) (concat acc-seqs (get-seqs-from-first curr-vec)))))]
                         (recur (vec (rest curr-vec)) (concat acc-seqs (pretty-get-seqs-from-first curr-vec)))))]
    (seqs-from-i v [])))

(defn naive-get-all-sums-seqs
  "Like recur-naive-get-all-sum seqs, but maybe more idiomatic. seq is divided
  into overlapping partitons of length 10 (max size of a sum seq) and then each 
  partition is run through get-seqs-from-first"
  [v]
  (apply concat (map pretty-get-seqs-from-first (partition-all 10 1 v))))

(defn pmap-get-all-sums-seqs
  "Like recur-naive-get-all-sum seqs, but maybe more idiomatic. seq is divided
  into overlapping partitons of length 10 (max size of a sum seq) and then each 
  partition is run through get-seqs-from-first"
  [v]
  (apply concat (pmap pretty-get-seqs-from-first (partition-all 10 1 v))))


;; sanity check tests
(def t [1 1 2 3 7])
(def u [1 1 2 3 1 7 8])

(apply concat (map pretty-get-seqs-from-first (partition-all 10 1 t)))
(= (naive-get-all-sums-seqs t) (recur-naive-get-all-sum-seqs t))
(= (naive-get-all-sums-seqs u) (recur-naive-get-all-sum-seqs u))


