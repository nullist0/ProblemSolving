# Graph Coloring By Constraint Programming

## Decision Variables

The decision variables are each nodes of graph.

## Values to assign

The values are colors. 

## Constraints

1. Two adjacent nodes of graph should not have the same color.

2. The size of the set of colors must be smaller than solutions found before.

## Search
### Labelling
We use Variable/Value labelling.

### Variable Ordering
The variables will be ordered by having the **least** domain and having the **most** number of adjacent nodes which is not colored.

### Value Ordering
The values will be ordered by having the **least** occurrence in the node-color array.

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