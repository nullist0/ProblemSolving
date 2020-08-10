#include <cstdio>

int arr[8];
int n, m;

int promise(int j){
    for(int i = 0; i < j; i++){
        if(arr[i] == arr[j]) return 0;
    }
    return 1;
}

void select(int i){
    if(i == m){
        for(int j = 0; j < m; j++)
            printf("%d ", arr[j]+1);
        printf("\n");
        return;
    }

    for(int j = 0; j < n; j++){
        arr[i] = j;
        if(promise(i))
            select(i+1);
    }
}

int main(void){
    scanf("%d %d", &n, &m);
    select(0);
    return 0;
}