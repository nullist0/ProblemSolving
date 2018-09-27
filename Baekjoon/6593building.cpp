#include <cstdio>
#include <queue>

using namespace std;

int building[31][31][31];
int l,r,c;

//z y x
int dir[6][3] = {{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};

int sx,sy,sz;
int ex,ey,ez;

int print(){
	printf("----------\n");
	for(int z = 0; z < l; z++){
		for(int y = 0; y < r; y++){
			for(int x = 0; x < c; x++){
				printf("%d ", building[z][y][x]);
			}
			printf("\n");
		}

		printf("\n\n");
	}
	printf("----------\n");
}

int bfs(){
	int res = 0;
	queue<pair<pair<int, int>, int> > q; // z y x

	q.push(make_pair(make_pair(sz, sy), sx));
	building[sz][sy][sx] = 1;

	while(!q.empty()){
		int z = q.front().first.first;
		int y = q.front().first.second;
		int x = q.front().second;

		q.pop();
		if(z == ez && y == ey && x == ex)
			return building[ez][ey][ex] - 1;

		for(int i = 0; i < 6; i++){
			int zz = z + dir[i][0];
			int yy = y + dir[i][1];
			int xx = x + dir[i][2];

			if(zz < 0 || zz >= l || yy < 0 || yy >= r || xx < 0 || xx >= c)
				continue;

			if(building[zz][yy][xx] == 0){
				building[zz][yy][xx] = building[z][y][x] + 1;
				q.push(make_pair(make_pair(zz, yy), xx));
			}
		}
	}
	return 0;
}

int main(){
	scanf("%d %d %d", &l, &r, &c);

	while(l != 0 && r != 0 && c != 0){
		for(int z = 0; z < l; z++){
			for(int y = 0; y < r; y++){
				for(int x = 0; x < c; x++){
					char t = 0;
					scanf(" %c", &t);
					if(t == '#')
						building[z][y][x] = 1;
					else{
						building[z][y][x] = 0;
						if(t == 'S'){
							sx = x;
							sy = y;
							sz = z;
						}else if(t == 'E'){
							ex = x;
							ey = y;
							ez = z;
						}
					}
				}
			}
		}

		int res = bfs();
		if(res == 0)
			printf("Trapped!\n");
		else
			printf("Escaped in %d minute(s).\n", res);

		scanf("%d %d %d", &l, &r, &c);
	}
}