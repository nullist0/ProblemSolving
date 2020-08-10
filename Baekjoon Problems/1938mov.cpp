#include <cstdio>
#include <queue>

using namespace std;

int n;
int ee[3], bb[3];
int mat[51][51];
int cache[2][51][51];

int ppos[8][2] = {{1, 1}, {-1, 1}, {1, -1}, {-1, -1},
				 {1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int isMovable(int y, int x, int s){
	if(x < 0 || x >= n || y < 0 || y >= n) return 0;
	if(mat[y][x] == 1) return 0;

	if(s){
		if(y-1 < 0 || y-1 >= n || y+1 < 0 || y+1 >= n) return 0;
		return mat[y-1][x] == 0 && mat[y+1][x] == 0;
	}
	else{
		if(x-1 < 0 || x-1 >= n || x+1 < 0 || x+1 >= n) return 0;
		return mat[y][x-1] == 0 && mat[y][x+1] == 0;
	}
}

int isTurnable(int y, int x, int s){
	int xx, yy;
	for(int i = 0; i < 8; i++){
		xx = x + ppos[i][0];
		yy = y + ppos[i][1];
		if(xx < 0 || xx >= n || yy < 0 || yy >= n) return 0;
		if(mat[yy][xx] == 1) return 0;
	}

	return 1;
}

int bfs(){
	int x, y, s, c, xx, yy, ss, cc;
	//count, position, state
	queue<pair<int, pair<pair<int, int>, int> > > q;

	q.push(make_pair(0, make_pair(make_pair(bb[0], bb[1]), bb[2])));

	cache[bb[2]][bb[0]][bb[1]] = 1;

	while(!q.empty()){
		y = q.front().second.first.first;
		x = q.front().second.first.second;
		c = q.front().first;
		s = q.front().second.second;

		if(y == ee[0] && x == ee[1] && s == ee[2]) return c;

		q.pop();
		cc = c+1;
		for(int i = 4; i < 8; i++){
			yy = y + ppos[i][0];
			xx = x + ppos[i][1];
			ss = s;

			if(isMovable(yy, xx, ss) && !cache[ss][yy][xx]){
				cache[ss][yy][xx] = 1;
				q.push(make_pair(cc, make_pair(make_pair(yy, xx), ss)));
			}
		}

		yy = y; xx = x; ss = !s;
		if(isTurnable(yy, xx, ss) && !cache[ss][yy][xx]){
			cache[ss][yy][xx] = 1;
			q.push(make_pair(cc, make_pair(make_pair(yy, xx), ss)));
		}
	}
	return 0;
}

int main(void){
	int b[3][2], bi = 0;
	int e[3][2], ei = 0;

	char c;

	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			scanf(" %c", &c);

			if(c == 'B'){
				mat[i][j] = 0;
				b[bi][0] = i;
				b[bi][1] = j;
				bi++;
			}
			
			else if(c == '0' || c == '1')
				mat[i][j] = c - '0';
			
			else{
				mat[i][j] = 0;
				e[ei][0] = i;
				e[ei][1] = j;
				ei++;
			}
		}
	}

	bb[0] = (b[0][0] + b[1][0] + b[2][0])/3;
	ee[0] = (e[0][0] + e[1][0] + e[2][0])/3;

	bb[1] = (b[0][1] + b[1][1] + b[2][1])/3;
	ee[1] = (e[0][1] + e[1][1] + e[2][1])/3;

	bb[2] = b[0][0] != b[1][0];
	ee[2] = e[0][0] != e[1][0];

	// printf("%d %d %d\n", bb[0], bb[1], bb[2]);
	// printf("%d %d %d\n", ee[0], ee[1], ee[2]);

	// for(int i = 0; i < n; i++){
	// 	for(int j = 0; j < n; j++){
	// 		printf("%d", mat[i][j]);
	// 	}
	// 	printf("\n");
	// }

	printf("%d\n", bfs());

	return 0;
}