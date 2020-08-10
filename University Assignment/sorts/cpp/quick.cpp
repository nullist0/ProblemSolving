#include "../headers/quick.h"

void quicksort::partition(int *pp, int low, int high){
    int j = low, pivot = low;
    int cache;
    for(int i = j; i <= high; i++){
        if(arr[i] < arr[pivot]){
            j++;
            cache = arr[j];
            arr[j] = arr[i];
            arr[i] = cache;
        }
    }
    cache = arr[j];
    arr[j] = arr[pivot];
    arr[pivot] = cache;
    *pp = j;
}

void quicksort::qsort(int low, int high){
    int pp = 0;
    if(low >= high) return;

    partition(&pp, low, high);

    qsort(low, pp-1);
    qsort(pp+1, high);
}
