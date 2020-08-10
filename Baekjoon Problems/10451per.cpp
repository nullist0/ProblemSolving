#include <cstdio>
#include <vector>
#include <queue>

int list[1000] = {0};

int bfs(){
	queue<int> q;


	while(!q.empty())
	{

	}
}

int main(void)
{
	int tc = 0, num = 0;

	scanf("%d", &tc);

	for(int i = 0; i < tc; i++)
	{
		scanf("%d", &num);
		for(int j = 0; j < num; j++)
		{
			scanf("%d", &list[j]);
			list[j]--;
		}

		for(int j = 0; j < num; j++){
			int cur = j;
			for(int k = 0; k < num; k++){
				
			}
		}
	}
}