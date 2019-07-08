#include <cstdio>
#include <vector>

int T;
int main(void){
	int N;
	int i, j;
	int x, y, R;
	vector<pair<pair<int, int>, int> > area;
	scanf("%d", &T);

	for(i = 0; i < T; i++){
		scanf("%d", &N);
		for(j = 0; j < N; j++){
			scanf("%d %d %d", &x, &y, &R);
			area.push_back(make_pair(make_pair(x, y), R));
		}
	}
	return 0;
}