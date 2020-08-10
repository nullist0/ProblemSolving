#include <queue>
#include <cstdio>

using namespace std;

int dir[4][2] = {{1, 0},{0, 1},{-1, 0},{0, -1}};
int map[301][301], cache[301][301];
int n, m, year = 0;

void bfs(int, int);

int melt(){
	int res = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(cache[i][j] < year && map[i][j] > 0){
				bfs(i, j);
				res++;
			}
		}
	}
	
	return res;
}

void bfs(int y, int x){
	queue<pair<int, int> > q, iceQ;
	q.push(make_pair(y, x));
	
	cache[y][x] = year;
	
	while(!q.empty()){
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		
		for(int i = 0; i < 4; i++){
			int yy = cy + dir[i][0];
			int xx = cx + dir[i][1];
			
			if(yy < 0 || yy >= n) continue;
			if(xx < 0 || xx >= m) continue;
			
			if(map[yy][xx] == 0)
				map[cy][cx]--;

			if(map[yy][xx] > 0 && cache[yy][xx] < year){
				q.push(make_pair(yy, xx));
				cache[yy][xx] = year;
			}
		}

		if(map[cy][cx] <= 0){
			iceQ.push(make_pair(cy, cx));
			map[cy][cx] = -1;
		}
	}

	while(!iceQ.empty()){
		int cy = iceQ.front().first;
		int cx = iceQ.front().second;
		iceQ.pop();

		map[cy][cx] = 0;
	}
}

int main(void){
	int cm;
	scanf("%d %d", &n, &m);
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			scanf("%d", &map[i][j]);
	
	for(year = 1; ; year++){
		cm = melt();
		if(cm >= 2){
			year--;
			break;
		}
		else if(cm == 0){
			year = 0;
			break;
		}
	}
	
	printf("%d\n", year);
	
	return 0;
}