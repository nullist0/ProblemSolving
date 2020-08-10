#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int R, C;
char map[21][21];
int route[26];

int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int res = 0;

void move(int y, int x, int ret){
	res = max(ret, res);
	if(route[map[y][x] - 'A'] == 0){
		route[map[y][x] - 'A'] = 1;

		int ny, nx;
		for(int i = 0; i < 4; i++){
			ny = dir[i][0] + y; nx = dir[i][1] + x;
			if((ny < 0 || ny >= R) || (nx < 0 || nx >= C))
				continue;
			if(route[map[ny][nx] - 'A'] == 0)
				move(ny, nx, ret + 1);
		}
		route[map[y][x] - 'A'] = 0;
	}
}

int main(void){
	scanf("%d %d", &R, &C);

	for(int y = 0; y < R; y++){
		for(int x = 0; x < C; x++){
			scanf(" %c", &map[y][x]);
		}
	}

	move(0, 0, 1);

	printf("%d\n", res);

	return 0;
}