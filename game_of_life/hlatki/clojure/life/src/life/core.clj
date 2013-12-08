(ns life.core
  (:refer-clojure :exclude [==])
  (:use clojure.core.logic)
  (:require [clojure.core.logic.fd :as fd]))


(defn get-all-cells
  "Get all possible cells.  Note that this does pretty much the same thing
  as life.io/all-cells-in-order, but here I used core.logic and the order of
  cells isn't guarenteed.  I kept this around because I think it's a nice simple 
  example of fd in action" 
  [rows cols]
  (run* [q]
    (fresh [i j]
      (fd/in i (fd/interval 0 rows))
      (fd/in j (fd/interval 0 cols))
      (== q [i j]))))



(defn get-neighbors
  "Return list of the eight cells surrounding cell r,c"
  [r c]
  (run* [q]
    (fresh [i j]
      (fd/in i (fd/interval (- r 1) (+ r 1)))
      (fd/in j (fd/interval (- c 1) (+ c 1)))
      (== q [i j])
      (!= q [r c]))))


(defn num-live-neighbors
  "Return number of living neighbors"
  [cells c]
  (count (filter #(some #{%} cells) (get-neighbors (first c) (second c)))))


(defn any-cells-with-3-neighbors
  "Return list of cells that have two neighbors"
  [cells rows colls]
  (filter #(=  (num-live-neighbors cells %) 3) (get-all-cells rows colls)))


(defn live-cells-with-2-live-neighbors
  "Return list of living cells that have 2 neighbors"
  [cells]
  (filter #(= (num-live-neighbors cells %) 2) cells))


(defn next-gen
  "Return list containing the next generation of living cells"
  [prev-gen rows cols]
  (run* [q]
    (fresh [i j]
      (fd/in i (fd/interval 0 rows))
      (fd/in j (fd/interval 0 cols))
      (== q [i j])
      (conde
        [(membero q (live-cells-with-2-live-neighbors prev-gen))]
        [(membero q (any-cells-with-3-neighbors prev-gen rows cols))]))))




