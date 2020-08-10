# Graph Coloring By Constraint Programming

## Decision Variables

The decision variables are each nodes of graph.

## Values to assign

The values are colors. 

## Constraints

1. Two adjacent nodes of graph should not have the same color.

2. The size of the set of colors must be smaller than solutions found before.

## Search
1. Variable Ordering : Order the variable by having the least domain and having the most number of adjacent nodes which is not colored.
2. Value Ordering

## Model
```
color[0..|V|]
edges[0..|E|]
maxSize
minimize
    max(color) + 1
global
    max(color) < maxSize
solve {
    foreach edge in edges{
        color[edge[0]] != color[edge[1]]
    }
}
```