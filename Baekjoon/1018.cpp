#include <algorithm>
#include <cstdio>

using namespace std;

char map[51][51];

int count(char s, int sx, int sy){

}

int main(void){
    int n, m, res = 51 * 51, cache;
    for(int y = 0; y < n; y++)
        for(int x = 0; x < m; x++)
            scanf("%c ", &map[y][x]);
    
    for(int y = 0; y + 8 < n; y++){
        for(int x = 0; x + 8 < m; x++){
            cache = min(count('B', x, y), count('W', x, y));
            res = min(res, cache);
        }
    }

    printf("%d\n", res);

    return 0;
}