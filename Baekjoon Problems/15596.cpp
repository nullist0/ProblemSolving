long long sum(int *a, int n){
	long long i = 0;
	long long total = 0;
	for(i = 0; i < n; i++)
		total += a[i];
	return total;
}
