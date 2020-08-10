#include <cstdio>
#include <queue>

using namespace std;

int F, S, G, U, D;
int cache[1000001];

int bfs(){

	int cur = 0, count = 0;
	queue<pair<int, int> > q;

	q.push(make_pair(S, 0));
	while(!q.empty()){
		cur = q.front().first;
		count = q.front().second;

		q.pop();

		if(cur == G) return count;
		if(cache[cur]) continue;

		cache[cur] = 1;

		if(cur + U <= F)
			q.push(make_pair(cur + U, count + 1));
		if(cur - D > 0)
			q.push(make_pair(cur - D, count + 1));
	}

	return -1;
}

int main(void)
{
	int res;
	scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);

	res = bfs();

	if(res >= 0) printf("%d\n", res);
	else printf("use the stairs\n");

	return 0;
}