# Knapsack
----------------

가방에 넣을 수 있는 무게, 넣을 물품의 무게와 가치가 주어졌을때, 가치를 최대로 만드는 물품 항목을 구하는 문제

## Mathematical Modelling

### Definition

가방 무게: K  
물품 :  I = {1, 2, 3, 4, ..., n}  
i번째 물품 가치 : v[i]  
i번째 물품 무게 : w[i]

### Decision variables

x[i] : i번째 물품이 선택되어있는지 여부를 판단하는 변수  
x[i] = if(i-th 물품이 선택됨) 1 else 0

### Problem constraint

sum(w[i] * x[i]) <= K

### Objective function

sum(v[i] * x[i])

## Solutions

### Dynamic Programming

#### Definition

O(k, j) : 용량이 k(0 <= k <= K)인 가방에 1..j(1 <= j <= n)의 물품을 가지고 넣었을 때의 가치 최대치

#### Finding Recurrence
 O(k, j)는 O(k, j-1)과 O(k - w[j], j - 1)를 이용하여 계산할 수 있다. O(k', j - 1)을 모든 k'에 대해 값을 계산을 이미한 상태라고 가정하자.  

 j번째 물품이 k보다 작을경우라면 두 경우가 생긴다.

 1. j번째 물품을 가방에 넣는경우
 이 경우 w[j]를 이미 넣었다고 생각하고 k - w[j]의 가방에 1..j-1의 물품을 이용하여 구한 최대값을 사용하면 이때의 최대치가 나온다.
즉, v[j] + O(k - w[j], j - 1)
 2. j번째 물품을 가방에 넣지않는 경우 : O(k, j - 1)
 이 경우 w[j]를 넣지 않았으므로, O(k, j - 1)이 최대치가 된다.

 j번째 물품이 k보다 큰 경우라면 가방에 넣지못하고 O(k, j - 1)과 같다.

위의 논의를 통해 O(k, j)의 식을 구할 수 있다.

```
O(k, j) =
 if(w[j] <= k) max(v[j] + O(k - w[j], j - 1), O(k, j - 1))
 else O(k, j - 1)
```

#### 알고리즘
##### Top-Down Approach

##### Bottom-Up Approach

### Branch and Bound



