(ns life.core
  (:refer-clojure :exclude [==])
  (:use clojure.core.logic)
  (:require [clojure.core.logic.fd :as fd]))


;; this is some test data
(def some-live-cells [[1 4] [2 3] [2 4]])

(defn get-cells
  [row-start row-end col-start col-end]
  (run* [q]
    (fresh [i j]
      (fd/in i (fd/interval row-start row-end))
      (fd/in j (fd/interval col-start col-end))
      (== q [i j]))))


(defn get-all-cells
  "Note that this returns a list"
  [rows cols]
  (get-cells 0 rows 0 cols))


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
  [cells i j]
  (count (filter #(some #{%} cells) (get-neighbors i j))))

(defn num-live-neighbors-d
  "Return number of living neighbors"
  [cells c]
  (count (filter #(some #{%} cells) (get-neighbors (first c) (second c)))))


(defn any-cells-with-3-neighbors
  "Return list of cells that have two neighbors"
  [cells rows colls]
  (filter #(=  (num-live-neighbors-d cells %) 3) (get-all-cells rows colls)))


(defn live-cells-with-2-live-neighbors
  "Return list of living cells that have 2 neighbors"
  [cells]
  (filter #(= (num-live-neighbors-d cells %) 2) cells))


(defn next-gen
  "Return list containg the next generation of living cells"
  [prev-gen rows cols]
  (run* [q]
    (fresh [i j]
      (fd/in i (fd/interval 0 rows))
      (fd/in j (fd/interval 0 cols))
      (== q [i j])
      (conde
        [(membero q (live-cells-with-2-live-neighbors prev-gen))]
        [(membero q (any-cells-with-3-neighbors prev-gen rows cols))]))))


(next-gen some-live-cells 4 7)


