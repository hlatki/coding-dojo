(ns poker.helper)

;; Helper functions for poker hand evaluation and comparison


;; ## Misc. functions

(defn consecutive?
  "Return true if a (sorted, descending) sequence of numbers is consecutive.
  Note that this will only work for positive numbers (since there are no positive
  numbers in poker)."
  [hand-vals]
  (second
    (reduce
     (fn [prev-vec curr]
       ;; prev-vec: [previous-num is-consecutive]
       ;; is-consecutive is false when it hits a nonconsecutive pairing
       (if (= (dec (first prev-vec)) curr)
         [curr (and (second prev-vec) true)]
         [curr (and (second prev-vec) false)]))
      [(inc (first hand-vals)) true]
      hand-vals)))

(defn all-same-suit?
  "Given a sequence containg the suits in a hand,
  return true if all cards in a hand are the same suit"
  [hand-suits]
  (apply = hand-suits))


;; ## Of a Kind functions
;; These functions deal with finding pairs and seeing if a hand has
;; four of a kind etc.

(defn n-of-a-kind
  "Return frequencies matching n (e.g. if you had a hand with values
  [5,5,6,8,4] and you were looking for pairs you would call (n-of-a-kind 2 [5,5,6,8,4])
  and would get [5 2] -- that is, there were two fives)"
  [n hand-values]
  (filter #(= (second %) n)
          (frequencies hand-values)))

(defn four-of-a-kind?
  "Return true if a hand has four of a kind"
  [hand-values]
  (not (empty? (n-of-a-kind 4 hand-values))))

(defn three-of-a-kind?
  "Return true if a hand has three of a kind"
  [hand-values]
  (not (empty? (n-of-a-kind 3 hand-values))))

;; ### Pairs

(defn pairs
  "Return frequencies of pairs in a hand (e.g. with hand [5,5,7,7,2] you would get
  back ([5 2] [7 2])"
  [hand-values]
  (n-of-a-kind 2 hand-values))

(defn pair?
  "Return true if there is at least one pair"
  [hand-values]
  (not (empty? (pairs hand-values))))

(defn two-pair?
  "Return true if the hand has two pairs"
  [hand-values]
  (= (count (pairs hand-values)) 2))








