#include <cstdio>
#include <queue>
#define MAX 256

using namespace std;

int map[MAX][MAX];

//BFS
int *find_path(int *path, int start, int end, int V){
    queue<int> q;
    int cache;
    q.push(start);
    while(!q.empty()){
        cache = q.front();
        q.pop();

        for(int dest = 0; dest < V; dest++){
            if(map[cache][dest] > 0)
                q.push(dest);
        }
    }

    return NULL;
}

int main(void){
    int V, E;
    int v1, v2, capacity;
    int path[MAX];
    scanf("%d %d", &V, &E);

    for(int i = 0; i < E; i++){
        scanf("%d %d %d", &v1, &v2, &capacity);
        map[v1][v2] = capacity;
    }

    return 0;
}