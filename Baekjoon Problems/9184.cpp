#include <cstdio>

// if a <= 0 or b <= 0 or c <= 0, then w(a, b, c) returns:
//     1

// if a > 20 or b > 20 or c > 20, then w(a, b, c) returns:
//     w(20, 20, 20)

// if a < b and b < c, then w(a, b, c) returns:
//     w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c)

// otherwise it returns:
//     w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1)

int memory[21][21][21];

void init() {
    for(int i = 0; i < 21; i++) {
        for(int j = 0; j < 21; j++) {
            for(int k = 0; k < 21; k++) {
                if(i == 0 || j == 0 || k == 0) {
                    memory[i][j][k] = 1;
                } else if(i < j && j < k) {
                    memory[i][j][k] = 
                            ((k - 1 <= 0) ? 1 : memory[i][j][k-1]) + 
                            ((j - 1 <= 0 || k - 1 <= 0) ? 1 : memory[i][j-1][k-1]) - 
                            ((j - 1 <= 0) ? 1 : memory[i][j-1][k]);
                } else {
                    memory[i][j][k] = 
                            ((i - 1 <= 0) ? 1 : memory[i-1][j][k]) +
                            ((i - 1 <= 0 || j - 1 <= 0) ? 1 : memory[i-1][j-1][k]) + 
                            ((i - 1 <= 0 || k - 1 <= 0) ? 1 : memory[i-1][j][k-1]) - 
                            ((i - 1 <= 0 || j - 1 <= 0 || k - 1 <= 0) ? 1 : memory[i-1][j-1][k-1]);
                }
            }
        }
    }
}

int w(int a, int b, int c) {
    if(a <= 0 || b <= 0 || c <= 0){
        return 1;
    } else if(a > 20 || b > 20 || c > 20){
        return memory[20][20][20];
    } else {
        return memory[a][b][c];
    }
}

int is_exit(int a, int b, int c) {
    return a == -1 && b == -1 && c == -1;
}

int main(void){
    int a = 0, b = 0, c = 0;
    init();

    scanf("%d %d %d", &a, &b, &c);
    
    while(!is_exit(a, b, c)) {
        printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));

        scanf("%d %d %d", &a, &b, &c);
    }
    
    return 0;
}