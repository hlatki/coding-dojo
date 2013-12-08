# Conway's Game of Life

This solution to the kata uses the logic programming tools in Clojure's 
[core.logic library](https://github.com/clojure/core.logic).

I haven't figured how to replace the ```any-cells-with-3-neighbors``` and
```live-cells-with-2-live-neighbors``` functions with declarative code, but 
hopefully I'll be able to.

## Usage
If you have [lein](https://github.com/technomancy/leiningen) (and don't mind 
waiting forever for the JVM to start up):

```
lein run <file-with-initial-state> <number-of-generations>
```
