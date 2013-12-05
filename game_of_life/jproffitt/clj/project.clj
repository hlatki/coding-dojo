(defproject conways-game "0.1.0-SNAPSHOT"
  :description "FIXME: write description"
  :url "http://example.com/FIXME"
  :license {:name "Eclipse Public License"
            :url "http://www.eclipse.org/legal/epl-v10.html"}
  :dependencies [[org.clojure/clojure "1.5.1"]
                 [org.clojure/clojurescript "0.0-2030"]]
  :main conways-game.main
  :plugins [[lein-cljsbuild "1.0.0"]]
  :cljsbuild {:crossovers [conways-game.core]
              :builds [{:source-paths ["src-cljs"]
                        :compiler {:output-to "target/js/main.js"
                                   :output-dir "target/out"
                                   :optimizations :advanced
                                   :pretty-print true}}]})

