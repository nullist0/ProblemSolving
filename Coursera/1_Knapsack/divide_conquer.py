K = int(input("K = "))
n = int(input("n = "))
v = list(map(lambda x: int(x), input("input values: ").split(" ")))
w = list(map(lambda x: int(x), input("input weights: ").split(" ")))

def O(k, j):
	if(j == -1):
		return 0
	elif(w[j] <= k):
		return max(v[j] + O(k - w[j], j - 1), O(k, j - 1))
	else:
		return O(k, j - 1)

print("result:", O(K, n - 1))
