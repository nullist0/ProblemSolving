#include <cstdio>
#define MAX 1024
#define INF 1e9

int map[MAX][MAX];
int dist[MAX];
int visited[MAX];
int prev[MAX];

int find_next(int V){
    int next = -1, next_cost = INF;
    for(int v = 0; v < V; v++){
        if(!visited[v] && next_cost > dist[v]){
            next_cost = dist[v];
            next = v;
        }
    }
    return next;
}

int main(void){
    int V, E, s;
    int v1, v2, c;
    scanf("%d %d %d", &V, &E, &s);

    for(int d = 0; d < V; d++)
        dist[d] = MAX;

    for(int i = 0; i < V; i++)
        for(int j = 0; j < V; j++)
            map[i][j] = i == j ? 0 : INF;

    for(int e = 0; e < E; e++){
        scanf("%d %d %d", &v1, &v2, &c);
        map[v1][v2] = c;
    }

    for(int v = 0; v < V; v++){
        dist[v] = INF;
        prev[v] = -1;
    }
    dist[s] = 0;

    int via;
    while((via = find_next(V)) != -1){
        visited[via] = 1;
        for(int dest = 0; dest < V; dest++){
            if(!visited[dest] && dist[dest] > dist[via] + map[via][dest]){
                dist[dest] = dist[via] + map[via][dest];
                prev[dest] = via;
            }
        }
    }

    return 0;
}