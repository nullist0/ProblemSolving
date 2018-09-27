#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int mat[26][26];
int cache[26][26];

int dir[4][2] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};

int bfs(int y, int x){
	int count = 0, yy, xx;
	queue<pair<int, int> > q;

	q.push(make_pair(y, x));
	cache[y][x] = 1;

	while(!q.empty()){
		y = q.front().first;
		x = q.front().second;

		count++;
		q.pop();

		for(int i = 0; i < 4; i++){
			yy = y + dir[i][0]; xx = x + dir[i][1];

			if(yy < 0 || yy >= n || xx < 0 || xx >= n) continue;
			if(mat[yy][xx] && !cache[yy][xx]){
				q.push(make_pair(yy, xx));
				cache[yy][xx] = 1;
			}
		}
	}

	return count;
}

int main(void){
	char c;
	vector<int> sizes;
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			scanf(" %c", &c);
			mat[i][j] = c - '0';
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(mat[i][j] && !cache[i][j])
				sizes.push_back(bfs(i, j));
		}
	}

	sort(sizes.begin(), sizes.end());

	printf("%d\n", sizes.size());
	for(int i = 0; i < sizes.size(); i++)
		printf("%d\n", sizes[i]);

	return 0;
}