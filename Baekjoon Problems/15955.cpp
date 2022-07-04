#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

vector<pair<int, int> > checkpoints;
int N;

int can_reach(int a, int b, int hp, int has_boost) {
	int src_x, src_y;
	int dest_x, dest_y;
	int dx, dy;
	long long length;

	src_x = checkpoints[a].first;
	src_y = checkpoints[a].second;

	dest_x = checkpoints[b].first;
	dest_y = checkpoints[b].second;

	dx = dest_x - src_x;
	dy = dest_y - src_y;

	length = (dx * dx) + (dy * dy);

	if(hp * hp >= length) {
		return 1;
	} else if((hp >= dy || hp >= dx) && has_boost) {
		return 1;
	}
	
	return 0;
}

int query(int a, int b, int x) {
	queue<int> 
}

int main(void) {
	int Q;
	int X, Y;
	int a, b, x;

	scanf("%d %d", &N, &Q);

	for(int i = 0; i < N; i++) {
		scanf("&d &d", &X, &Y);

		checkpoints.push_back(make_pair(X, Y));
	}

	for(int i = 0; i < Q; i++) {
		scanf("%d %d %d", &a, &b, &x);
		printf("%s\n", query(a, b, x) ? "YES" : "NO");
	}

	return 0;
}