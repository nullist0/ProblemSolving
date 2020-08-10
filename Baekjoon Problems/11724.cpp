#include <cstdio>
#include <vector>

using namespace std;

int *vertices[1001];
int values[1001];

int main(void){
	int N, M, u, v, p = 0, ret = 0;

	int single = -1, empty = -2;
	int cache;

	scanf("%d %d", &N, &M);

	for(int i = 0; i < N; i++){
		values[i] = i;
		vertices[i] = &single;
	}

	for(int i = 0; i < M; i++){
		scanf("%d %d", &u, &v);
		u--; v--;
		if(vertices[u] == &single && vertices[v] == &single)
			vertices[u] = vertices[v] = &values[p++];
		else if(vertices[u] == &single)
			vertices[u] = vertices[v];
		else if(vertices[v] == &single)
			vertices[v] = vertices[u];
		else
			*vertices[v] = *vertices[u];
	}

	for(int i = 0; i < N; i++){
		if(vertices[i] == &single){
			ret++;
			vertices[i] = &empty;
		}
		else if(vertices[i] != &empty){
			ret++;
			cache = *vertices[i];
			for(int j = 0; j < N; j++){
				if(*vertices[j] == cache)
					vertices[j] = &empty;
			}
		}
	}

	printf("%d\n", ret);

	return 0;
}

// void test(){
// 	for(int i = 0; i < 100; i++){
// 		if(i % 2 == 0)
// 			vertices[i] = values + 0;
// 		else
// 			vertices[i] = values + 1;
// 	}

// 	scanf("%d %d", values + 0, values + 1);

// 	for(int i = 0; i < 10; i++){
// 		for(int j = 0; j < 10; j++){
// 			printf("[%d]", *vertices[10 * i + j]);
// 		}
// 		printf("\n");
// 	}
// 	printf("\n");
// }
