#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

vector<pair<int, int> > checkpoints, sortedpointsX, sortedpointsY;
int N, Q;

double dist(int from, int to){
	int fx = checkpoints[from].first, fy = checkpoints[from].second;
	int nx = checkpoints[to].first, ny = checkpoints[to].second;
	int dx = fx - nx, dy = fy - ny;

	return min(dx, dy);
}

int main(void){
	int x, y;
	int cache[N];

	scanf("%d %d", &N, &Q);

	for(int i = 0; i < N; i++){
		scanf("%d %d", &x, &y);
		checkpoints.push_back(make_pair(x, y));
		sortedpointsX.push_back(make_pair(x, i));
		sortedpointsY.push_back(make_pair(y, i));
		
		cache[i] = 0;
	}

	sort(sortedpointsX.begin(), sortedpointsX.end());
	sort(sortedpointsY.begin(), sortedpointsY.end());

	for(int qt = 1; qt <= Q; qt++){
		int from, to, hp;
		scanf("%d %d %d", &from, &to, &hp);

		from--; to--;
		queue<int> q;
		q.push(from);

		cache[from] = qt;

		while(!q.empty()){
			int current = q.front();
			int cx = checkpoints[current].first, cy = checkpoints[current].second;

			q.pop();
			//printf("%d : %d\n", qt, current);

			for(int j = 0; j < N; j++){
				if(cache[j] == qt) continue;
				int nx = sortedpointsX[j].first, nxi = sortedpointsX[j].second;
				int ny = sortedpointsY[j].first, nyi = sortedpointsY[j].second;

				if(nx > cx + hp && ny > cy + hp) break;

				if(cx - hp <= nx && nx <= cx + hp && cache[nxi] != qt){
					cache[nxi] = qt;
					q.push(nxi);
				}
				if(cy - hp <= ny && ny <= cy + hp && cache[nyi] != qt){
					cache[nyi] = qt;
					q.push(nyi);
				}
			}
			if(cache[to] == qt)
				break;
		}
		if(cache[to] == qt)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}