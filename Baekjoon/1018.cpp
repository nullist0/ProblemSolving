#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

int map[51][51];

int count(int s, int sx, int sy){
    int res = 0;

    for(int y = 0; y < 8; y++){
        for(int x = 0; x < 8; x++){
            res += map[y + sy][x + sx] != abs(s - (x + y) % 2);
        }
    }

    return res;
}

int main(void){
    int n, m, res = 51 * 51;
    char cache;

    scanf("%d %d", &n, &m);

    for(int y = 0; y < n; y++){
        for(int x = 0; x < m; x++){
            scanf(" %c", &cache);
            if(cache == 'B')
                map[y][x] = 0;
            else
                map[y][x] = 1;
        }
    }
    
    for(int y = 0; y + 8 <= n; y++){
        for(int x = 0; x + 8 <= m; x++){
            res = min(res, min(count(0, x, y), count(1, x, y)));
        }
    }

    printf("%d\n", res);

    return 0;
}