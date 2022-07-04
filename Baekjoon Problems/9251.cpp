#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define max3(x, y, z) max((x), max((y), (z)))

char input[2][1001];

int LCS() {
    int N = strlen(input[0]);
    int M = strlen(input[1]);

    int localLCS[N][M];

    // localLCS[n][m] = localLCS[n-1][m-1] if input[0][n] != input[1][m]
    //                = localLCS[n-1][m-1] + 1 if input[0][n] == input[1][m]

    for(int n = 0; n < N; n++) {
        for(int m = 0; m < M; m++) {
            if(n == 0 || m == 0) {
                localLCS[n][m] = max3(
                    input[0][n] == input[1][m] ? 1 : 0, 
                    n > 0 ? localLCS[n-1][m] : 0, 
                    m > 0 ? localLCS[n][m-1] : 0
                );
            }
            else {
                localLCS[n][m] = max(localLCS[n-1][m], localLCS[n][m-1]);
                if(input[0][n] == input[1][m]) {
                    localLCS[n][m] = max(localLCS[n-1][m-1] + 1, localLCS[n][m]);
                }
            }
        }
    }
    
    return localLCS[N-1][M-1];
}

int main(void) {

    scanf("%s", input[0]);
    scanf("%s", input[1]);

    printf("%d\n", LCS());

    return 0;
}