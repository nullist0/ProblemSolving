import itertools

N = int(input())
arr = list(map(int, input().split()))

LIS = 1

for r in range(2, len(arr) + 1):
    for c in itertools.combinations(arr, r):
        if all(map(lambda i:  c[i] < c[i+1], range(r - 1))):
            LIS = r
        if LIS == r:
            break

print(LIS)