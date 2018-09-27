#include <cstdio>
#include <queue>
#include <cmath>

using namespace std;

int prime[10001];
int cache[10001];

int bfs(int cn, int s, int e){
	queue<pair<int, int> > q;

	cache[s] = 1;
	q.push(make_pair(s, 0));
	while(!q.empty()){
		int x = q.front().first, count = q.front().second;
		q.pop();

		cache[x] = cn;

		if(x == e)
			return count;

		for(int i = 0; i <= 9; i++){
			int a = i * 1000 + x % 1000;
			int b = (x / 1000) * 1000 + i * 100 + x % 100;
			int c = (x / 100) * 100 + i * 10 + x % 10;
			int d = (x / 10) * 10 + i * 1;

			if(cache[a] != cn && i != 0 && prime[a] == 0)
				q.push(make_pair(a, count+1));
			
			if(cache[b] != cn && prime[b] == 0)
				q.push(make_pair(b, count+1));
			
			if(cache[c] != cn && prime[c] == 0)
				q.push(make_pair(c, count+1));
			
			if(cache[d] != cn && prime[d] == 0)
				q.push(make_pair(d, count+1));
		}
	}
	return -1;
}

int main(){

	int n = 0, s = 0, e = 0;
	scanf("%d", &n);

	int c = 0;
	for(int i = 1000; i <= 10000; i++){
		if(i % 2 == 0 || i % 3 == 0){
			prime[i] = 1;
		}
		else{
			for(int j = 3; j <= (int)sqrt(i); j++){
				if(i % j == 0){
					prime[i] = 1;
				}
			}
		}
	}

	// printf("%d\n", c);

	for(int i = 0; i < n; i++){
		scanf("%d %d", &s, &e);

		int res = bfs(i+1, s, e);
		if(res == -1)
			printf("Impossible\n");
		else
			printf("%d\n", res);
	}

	return 0;
}