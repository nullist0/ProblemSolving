#include <cstdio>
#define MAX 256
#define INF 1e9

int map[MAX][MAX];
int main(void){
    int V, E;
    int v1, v2, c;

    scanf("%d %d", &V, &E);

    for(int v1 = 0; v1 < V; v1++)
        for(int v2 = 0; v2 < V; v2++)
            map[v1][v2] = INF;

    for(int e = 0; e < E; e++){
        scanf("%d %d %d", &v1, &v2, &c);
        map[v1][v2] = c;
    }

    for(int s = 0; s < V; s++){
        for(int d = 0; d < V; d++){
            for(int via = 0; via < V; via++){
                if(map[s][d] > map[s][via] + map[via][d])
                    map[s][d] = map[s][via] + map[via][d];
            }
        }
    }

    printf("RESULT\n");
    printf("\t");
    for(int d = 0; d < V; d++){
        printf("%d\t", d);
    }
    printf("\n");

    for(int s = 0; s < V; s++){
        printf("%d\t", s);
        for(int d = 0; d < V; d++){
            if(map[s][d] == INF)
                printf("X\t");
            else
                printf("%d\t", map[s][d]);
        }
        printf("\n");
    }

    return 0;
}