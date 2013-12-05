(ns conways-game.web
  (:require [conways-game.core :as core]))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Defs and forward declarations

(def canvas (.getElementById js/document "canvas"))
(def next-button (.getElementById js/document "next-position"))
(def ctx (.getContext canvas "2d"))

(def empty-color "#FFFFFF")
(def fill-color "#888888")
(def grid-color "#888888")

(def board (atom (core/build-initial-grid 20 20)))

(declare board-properties)
(declare draw-board)

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; click handlers

(defn get-offset
  "Calculate the offset of the element relative to body."
  [o]
  (loop [curr o
         off-x (.-offsetLeft o)
         off-y (.-offsetTop o)]
    (if-let [parent (.-offsetParent curr)]
      (recur
        parent
        (+ off-x (.-offsetLeft parent))
        (+ off-y (.-offsetTop parent)))
      [off-x off-y])))

(defn flip-clicked-cell
  [x y board]
  (let [{cell-height :cell-height
         cell-width  :cell-width} (board-properties canvas @board)
        col-cell (int (/ x cell-width))
        row-cell (int (/ y cell-height))
        new-val (if (= (get-in @board [col-cell row-cell]) \.) \* \.)]
    (swap! board assoc-in [col-cell row-cell] new-val)
    (draw-board canvas @board)))

(defn change-cell
  "Calculate the position clicked in the canvas and then invert the value at
   the corresponding location on the board."
  [e]
  (this-as this
    (let [[off-x off-y] (get-offset this)
          x (- (.-x e) off-x)
          y (- (.-y e) off-y)]
      (flip-clicked-cell x y board))))

(defn get-next-position
  "Calculate the next state of the board from the current state."
  [e]
  (do
    (swap! board core/get-next-position)
    (draw-board canvas @board)))

(.addEventListener canvas "click" change-cell false)
(.addEventListener next-button "click" get-next-position false)

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; canvas context helpers - return the context for easy threading.

(defn set-color!
  [c color]
  (do
    (set! (.-fillStyle c) color)
    c))

(defn line-to!
  [c x y]
  (do
    (.lineTo c x y)
    c))

(defn move-to!
  [c x y]
  (do
    (.moveTo c x y)
    c))

(defn draw-rect!
  [c x0 y0 x1 y1]
  (do
   (.fillRect c x0 y0 x1 y1)
    c))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; 

(defn draw-line!
  [c x0 y0 x1 y1]
  (-> c
      (move-to! x0 y0)
      (line-to! x1 y1)
      (.stroke)))

(defn board-properties
  [canvas board]
  (let [x-pix (.-scrollWidth canvas)
        y-pix (.-scrollHeight canvas)
        vert-cells (count board)
        horz-cells (count (nth board 0))
        cell-height (/ y-pix vert-cells)
        cell-width (/ x-pix horz-cells)]
    {:x-pixels x-pix
     :y-pixels y-pix
     :rows vert-cells 
     :cols horz-cells
     :cell-height cell-height
     :cell-width cell-width}))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Board drawing functions 

(defn draw-cell
  [c x y width height color]
  (-> c
      (set-color! color)
      (draw-rect! (* x width)
                  (* y height)
                  (+ (* x width) width)
                  (+ (* y height) height))))

(defn draw-lines
  [c width height vert-cells horz-cells color]
  (do
    (set-color! c color)
    (doseq [col (range horz-cells)]
      (draw-line! c (* col width) 0 (* col width) (* height vert-cells)))
    (doseq [row (range vert-cells)]
      (draw-line! c 0 (* row height) (* width horz-cells) (* row height)))))

(defn clear-board
  [c]
  (-> c
      (set-color! empty-color)
      (.clearRect 0 0 (.-scrollWidth canvas) (.-scrollHeight canvas))))

(defn draw-board
  [canvas board]
  (let [{rows :rows
         cols :cols
         cell-height :cell-height
         cell-width  :cell-width} (board-properties canvas board)
        c ctx]
    (clear-board c)
    (doseq [row (range rows)
            col (range cols)] 
      (draw-cell c row col cell-width cell-height (if (= (get-in board [row col]) \.)
                                                    empty-color
                                                    fill-color)))
    (draw-lines c cell-width cell-height rows cols grid-color)))

(draw-board canvas @board)
