def O(K, n, v, w):
	Olist = []
	def calc(k, i):
		if(i == -1):
			return 0
		elif(w[i] <= k):
			return max(v[i] + Olist[i][k - w[i]], Olist[i][k])
		else:
			return Olist[i][k]
	for i in range(-1, n):
		cache = []
		for k in range(K+1):
			cache += [calc(k, i)]
		Olist += [cache]
	return Olist

def track(Olist, K, n, w):
	result = []
	capacity = K
	for i in range(n):
		item = n - i
		if(Olist[item][capacity] != Olist[item-1][capacity]):
			result += [item - 1]
			capacity -= w[item - 1]
	return result

def execute():
	K = int(input("K = "))
	n = int(input("n = "))
	v = list(map(lambda x: int(x), input("input values: ").split(" ")))
	w = list(map(lambda x: int(x), input("input weights: ").split(" ")))
	Olist = O(K, n, v, w)
	print("Result: ", Olist[n][K])
	print("Items: ", track(Olist, K, n, w))

execute()
