(ns conways-game.main
  (:require [conways-game.reader :as reader]))

(defn -main
  [& args]
  (while true 
    (print "\nReady for your input => ")
    (flush)
    (try
      (println (str "\n" (reader/read-user-input)))
      (catch Exception e
        (print "Something went wrong! Quick, here's a stacktrace:\n")
        (flush)
        (.printStackTrace e)))))
