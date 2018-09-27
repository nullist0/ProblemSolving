#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int R, C;
char mat[21][21];

/*
2 4
CAAB
ADCB
*/

int dfs(int x, int y, string cur){
	int res = 0;
	if(cur.find(mat[y][x]) != string::npos)
		return 0;

	cur += mat[y][x];
	//cout << y << "," << x << ":" << cur << endl;
	
	if(x + 1 < C)
		res = max(res, 1 + dfs(x + 1, y, cur));
	if(y + 1 < R)
		res = max(res, 1 + dfs(x, y + 1, cur));
	if(x - 1 >= 0)
		res = max(res, 1 + dfs(x - 1, y, cur));
	if(y - 1 >= 0)
		res = max(res, 1 + dfs(x, y - 1, cur));

	return res;
}

int main(void)
{
	scanf("%d %d", &R, &C);

	for(int i = 0; i < R; i++)
		for(int j = 0; j < C; j++)
			scanf(" %c", &mat[i][j]);

	printf("%d\n", dfs(0, 0, ""));
	return 0;
}