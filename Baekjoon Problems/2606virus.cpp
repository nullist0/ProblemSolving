#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

// int coms[101];
// int link[101][101];

// int main(){

// 	int n = 0, m = 0;
// 	scanf("%d %d", &n, &m);

// 	int t1, t2;

// 	for(int i = 1; i < 101; i++){
// 		for(int j = 1; j < 101; j++){
// 			if(i == j)
// 				link[i][j] = 1;
// 		}
// 	}

// 	for(int i = 0; i < m; i++){
// 		scanf("%d %d", &t1, &t2);
// 		link[t1][t2] = 1;
// 		link[t2][t1] = 1;
// 	}

// 	int count = 0;
// 	coms[1] = 1;

// 	for(int k = 1; k <= n; k++){
// 		for(int i = 1; i <= n; i++){
// 			for(int j = 1; j <= n; j++){
// 				if(((coms[i] == 1 && coms[j] == 0) || (coms[j] == 1 && coms[i] == 0)) 
// 					&& link[i][k] + link[k][j] == 2 && i != j){
// 					// printf("%d, %d, %d\n", i, k, j);
// 					coms[j] = 1;
// 					coms[i] = 1;
// 					count++;
// 				}
// 			}
// 		}
// 	}

// 	printf("%d\n", count);
// }

int coms[101];
int link[101][101];

int n;

int bfs(){
	queue<int> q;
	int count = 0;

	q.push(1);

	while(!q.empty()){
		int t = q.front();
		q.pop();

		if(coms[t] == 1)
			continue;

		coms[t] = 1;
		count++;

		for(int j = 1; j <= n; j++){
			if(link[t][j] == 1)
				q.push(j);
		}
	}

	return count-1;
}

int main(){
	int m = 0;
	scanf("%d %d", &n, &m);

	int from = 0, to = 0;

	for(int i = 0; i < m; i++){
		scanf("%d %d", &from, &to);
		link[from][to] = 1;
		link[to][from] = 1;
	}

	printf("%d\n", bfs());

	return 0;
}