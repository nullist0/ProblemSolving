#include <vector>
#include <cstdio>

using namespace std;

int map[128][128];

int check(int x, int y, int size) {
    int color = map[y][x];
    for(int cy = y; cy < y + size; cy++) {
        for(int cx = x; cx < x + size; cx++) {
            if(color != map[cy][cx]) {
                return -1;
            }
        }
    }
    return color;
}

void cut(int x, int y, int size, pair<int, int> *count) {
    int color;
    if((color = check(x, y, size)) != -1) {
        if(color == 0) {
            (count -> first) ++;
        }
        else {
            (count -> second) ++;
        }
    } else {
        size = size / 2;
        cut(x, y, size, count);
        cut(x + size, y, size, count);
        cut(x, y + size, size, count);
        cut(x + size, y + size, size, count);
    }
}

int main(void) {
    int N;
    pair<int, int> count;
    scanf("%d", &N);

    for(int y = 0; y < N; y++) {
        for(int x = 0; x < N; x++) {
            scanf("%d", &map[y][x]);
        }
    }

    cut(0, 0, N, &count);

    printf("%d\n%d\n", count.first, count.second);

    return 0;
}