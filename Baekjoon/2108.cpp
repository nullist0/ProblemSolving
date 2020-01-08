#include <cstdio>
#include <algorithm>

using namespace std;

int data[500000], common[8001] = {0, };
int N, total = 0;

int main(void){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &data[i]);
        total += data[i];
        common[data[i]+4000]++;
    }

    int current = 0, M = 0;
    for(int i = 0; i < 8001; i++){
        if(current < common[i]){
            M = i - 4000;
            current = common[i];
        }
    }

    for(int i = M + 4000 + 1; i < 8001; i++)
        if(current == common[i]){
            M = i - 4000;
            break;
        }

    sort(data, data+N);

    printf("%d\n", (int)((double)total / N + (total >= 0 ? 0.5 : -0.5)));
    printf("%d\n", data[(N+1)/2-1]);
    printf("%d\n", M);
    printf("%d\n", data[N-1]-data[0]);
    return 0;
}