#include <vector>
#include <cstdio>

using namespace std;

int map[64][64];

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

void compress(int x, int y, int size) {
    int color;
    if((color = check(x, y, size)) != -1) {
        printf("%d", color);
    } else {
        size = size / 2;
        printf("(");
        compress(x, y, size);
        compress(x + size, y, size);
        compress(x, y + size, size);
        compress(x + size, y + size, size);
        printf(")");
    }
}

int main(void) {
    int N;
    scanf("%d", &N);

    for(int y = 0; y < N; y++) {
        for(int x = 0; x < N; x++) {
            scanf(" %c", &map[y][x]);
            map[y][x] -= '0';
        }
    }

    compress(0, 0, N);
    printf("\n");

    return 0;
}