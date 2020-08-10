#include <cstdio>
#include <algorithm>
#define INF 1e9

using namespace std;

int n, k, l;
int minPal[10001], currentU[10001];
char w[10001];

int isThetaPal(int w, int u){
    return k * w <= 2 * u * l;
}

int main(void){
    scanf("%d %d %d", &n, &k, &l);
    scanf("%s", w);

    for(int i = 0; i <= n; i++) minPal[i] = INF;

    for(int l = 2; l <= n; l++){
        for(int p = l-1; p > 0; p--){
            
        }
    }

    return 0;
}