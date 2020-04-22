#include <cstdio>
#define MAX 256

int cl[MAX][MAX];

int main(void){
    int V, E;
    int v1, v2, c;

    scanf("%d %d", &V, &E);

    for(int e = 0; e < E; e++){
        scanf("%d %d", &v1, &v2);
        cl[v1][v2] = 1;
    }

    for(int s = 0; s < V; s++){
        for(int e = 0; e < V; e++){
            for(int via = 0; via < V; via++){
                cl[s][e] = cl[s][e] || (cl[s][via] && cl[via][e]);
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
            if(!cl[s][d])
                printf("X\t");
            else
                printf("O\t");
        }
        printf("\n");
    }

    return 0;
}