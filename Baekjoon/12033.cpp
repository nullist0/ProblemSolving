#include <cstdio>

int main(void){
    int T, N;
    int arr[8] = {0,};
    int min, max, cache;
    scanf("%d", &T);

    for(int i = 1; i <= T; i++){
        scanf("%d", &N);
        for(int j = 0; j < N * 2; j++)
            scanf("%d", &arr[j]);

        min = 0; max = 2 * N - 1;
        while(min < max && arr[min] != 0 && arr[max] != 0){
            // printf("%d %d:", min, max);
            // for(int j = 0; j < N * 2; j++)
            //     printf(" %d", arr[j] * -1);
            // printf("\n");

            cache = arr[min] / 3 * 4;
            
            arr[min] *= -1;
            for(int k = min + 1; k < 2 * N; k++){
                if(arr[k] == cache){
                    arr[k] = 0;
                    break;
                }
            }
            
            cache = arr[max] / 4 * 3;

            arr[max] = 0;
            for(int k = max - 1; k > 0; k--){
                if(arr[k] == cache){
                    arr[k] *= -1;
                    break;
                }
            }
            
            for(; min < 2 * N ; min++){
                if(arr[min] > 0) break;
            }
            
            for(; max > 0; max--){
                if(arr[max] > 0) break;
            }
        }

        printf("Case #%d:", i);
        for(int j = 0; j < N * 2; j++)
            if(arr[j] != 0)
                printf(" %d", arr[j] * -1);
        printf("\n");
    }

    return 0;
}
