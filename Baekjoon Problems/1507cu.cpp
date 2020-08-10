#include <cstdio>
#include <queue>

#define INF 9999999

int mat[21][21];
int des[21][21];

int d(int n)
{

	// int res = 0;

	// for(int i = 1; i <= n; i++)
	// {
	// 	for(int j = 1; j <= n; j++)
	// 	{
	// 		des[i][j] = INF;
	// 	}
	// }

	// print(n);

	// for(int i = 1; i <= n; i++)
	// {
	// 	for(int j = 1; j <= n; j++)
	// 	{
	// 		if(i == j) continue;
	// 		for(int k = 1; k <= n; k++)
	// 		{
	// 			if(mat[i][k] + mat[k][j] < des[i][j])
	// 			{
	// 				des[i][j] = mat[i][k] + mat[k][j];
	// 				des[j][i] = mat[j][k] + mat[k][i];
	// 			}
	// 		}
	// 	}
	// }

	// print(n);
}

int main(void)
{
	int n = 0, input;
	scanf("%d", &n);

	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			scanf("%d", &input);
			mat[i][j] = input;
		}
	}

	d(n);

	return 0;
}
