#include <cstdio>
#include <vector>

using namespace std;

int **vertices[1001];
int *partial[1001];
int graph[1001];

int main(void){
	int N, M, u, v, p = 0, ret = 0;

	scanf("%d %d", &N, &M);

	for(int i = 0; i < N; i++){
        graph[i] = 1;
        partial[i] = graph + i;
		vertices[i] = partial + i;
    }

	for(int i = 0; i < M; i++){
		scanf("%d %d", &u, &v);
		u--; v--;

        if(**vertices[v] == 1){
            (**vertices[v])--;
            (**vertices[u])++;
            vertices[v] = vertices[u];
        }
        else if(**vertices[u] == 1){
            (**vertices[u])--;
            (**vertices[v])++;
            vertices[u] = vertices[v];
        }
        else if(*vertices[v] != *vertices[u]){
            **vertices[u] += **vertices[v];
            **vertices[v] = 0;
            *vertices[v] = *vertices[u];
        }
	}

    for(int i = 0; i < N; i++)
        ret += graph[i] > 0;

	printf("%d\n", ret);

	return 0;
}