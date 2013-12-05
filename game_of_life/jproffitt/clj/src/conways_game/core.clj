(ns conways-game.core)

(defn get-neighbors
  [r c]
  [[(- r 1) (- c 1)] [(- r 1)  c] [(- r 1) (+ c 1)]
   [r (- c 1)]                    [r (+ c 1)]
   [(+ r 1) (- c 1)] [(+ r 1)  c] [(+ r 1) (+ c 1)]])

(defn build-initial-grid
  [r-size c-size]
  (vec (for [r (range r-size)]
         (vec (for [c (range c-size)] \.)))))

(defn is-alive?
  [grid rc]
  (= (get-in grid rc) \*))

(defn alive-neighbors
  [grid [r c]]
  (filter (partial is-alive? grid) (get-neighbors r c)))

(defn goldie-locks-filter
  [value neighbors]
  (if (>= 3 (count neighbors) 2)
    \*
    \.))

(defn new-life-filter
  [value neighbors]
  (if (= 3 (count neighbors))
    \*
    \.))

(defn get-next-position
  [grid]
  (let [max-r (count grid)
        max-c (count (nth grid 0))]
    (loop [next-pos (build-initial-grid max-r max-c)
           curr-r 0
           curr-c 0]
      (let [curr-val (get-in grid [curr-r curr-c])
            neighbors (alive-neighbors grid [curr-r curr-c])
            next-val (if (= curr-val \*)
                       (goldie-locks-filter curr-val neighbors)
                       (new-life-filter curr-val neighbors))]
        (if-not (and
                  (= max-r (inc curr-r))
                  (= max-c (inc curr-c)))
          (recur
            (assoc-in next-pos [curr-r curr-c] next-val)
            (if (> max-c (inc curr-c)) curr-r (inc curr-r))
            (if (> max-c (inc curr-c)) (inc curr-c) 0))
          (assoc-in next-pos [curr-r curr-c] next-val))))))

(defn convert-str-to-vec
  [s]
  (let [s-vec (clojure.string/split-lines s)
        get-cell-fn (fn [v] v)]
    (mapv (fn [t] (mapv get-cell-fn t)) s-vec)))

(defn get-nth-position
  [grid n]
  (if (> n 0)
    (get-nth-position (get-next-position grid) (dec n))
    grid))

(defn vec-to-string
  [ve]
  (let [char-cat-fn (fn [v] (apply str v))
        line-cat-fn (fn [s t] (str s "\n" t))]
    (reduce line-cat-fn
            (map char-cat-fn ve))))

(comment
  (get-next-position [[\. \* \*] [\. \* \*]])
  (alive-neighbors [[\* \*] [\* \*]] [1 1])
  (get-neighbors [[\* \*] [\* \*]] [0 0])
  )
