#include <cstdio>
#include <queue>
#include <vector>

#define MAX 256
#define INF 1e9

using namespace std;

int map[MAX][MAX];
int dist[MAX], prev_vertex[MAX];

int main(void){
    int V, E, source, via;
    int v1, v2, cost;

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

    for(int s = 0; s < V; s++)
        for(int d = 0; d < V; d++)
            map[s][d] = INF;

    scanf("%d %d %d", &V, &E, &source);
    for(int e = 0; e < E; e++){
        scanf("%d %d %d", &v1, &v2, &cost);
        map[v1][v2] = cost;
    }

    for(int v = 0; v < V; v++){
        dist[v] = INF;
    }

    dist[source] = 0;
    pq.push(make_pair(0, source));

    while(!pq.empty()){
        via = pq.top().second;
        pq.pop();

        for(int v = 0; v < V; v++){
            if(dist[v] > dist[via] + map[via][v]){
                dist[v] = dist[via] + map[via][v];
                prev_vertex[v] = via;

                pq.push(make_pair(dist[v], v));
            }
        }
    }

    return 0;
}