#include <vector>
#include <cstdio>
#include <queue>

using namespace std;

int mat[101][101];
int cache[101][101];
int n = 0, m = 0;

int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int prn(){
	printf("\n");
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++)
			printf("%d ", mat[i][j]);
		printf("\n");
	}
}

// int bfs(int time){
// 	queue<pair<int, pair<int, int> > > q;
// 	q.push(make_pair(0, make_pair(0, 0)));

// 	int count = 0, k = time%2;

// 	while(!q.empty()){
// 		int s = q.front().first;
// 		int y = q.front().second.first, x = q.front().second.second;

// 		cache[y][x] = 1;

// 		q.pop();

// 		for(int i = 0; i < 4; i++){
// 			int xx = x + dir[i][0], yy = y + dir[i][1];

// 			if(xx < 0 || xx >= m || yy < 0 || yy >= n) continue;

// 			if(cache[yy][xx] == 0){
// 				if(mat[yy][xx] == 0){
// 					q.push(make_pair(s, make_pair(yy, xx)));
// 				}else{
// 					mat[yy][xx] = s+1;
// 					q.push(make_pair(s+1, make_pair(yy, xx)));
// 				}
// 			}
// 		}
// 	}

// 	prn();
// 	return count;
// }

int main(){

	scanf("%d %d", &n, &m);

	for(int y = 0; y < n; y++){
		for(int x = 0; x < m; x++){
			scanf("%d", &mat[y][x]);
		}
	}
	
	int time = 1, count = 0, pre = 0;
	for(time = 1; ; time++){
		count = 0;
		for(int y = 0; y < n; y++){
			for(int x = 0; x < m; x++){
				if(mat[y][x] == time){
					int mul = 1;
					for(int i = 0; i < 4; i++)
						mul *= mat[y + dir[i][0]][x + dir[i][1]];
					if(mul >= time * time * time * time){
						mat[y][x] = time + 1;
						count++;
					}
				}
			}
		}

		if(count == 0)
			break;
		pre = count;
	}

	// int pre = 0, next = 0, time = 2;

	// for(time = 2; ; time++){
	// 	next = bfs(time);
	// 	if(next == 0)
	// 		break;
	// 	pre = next;
	// }

	prn();

	printf("%d\n", --time);
	printf("%d\n", pre);
}
