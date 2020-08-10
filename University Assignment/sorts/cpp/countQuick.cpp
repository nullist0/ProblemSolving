#include "../headers/countquick.h"

void countQuicksort::partition(int *pp, int low, int high){
    int j = low, pivot = low, cache;
    int i = j;
    assignment += 3;
    while(i <= high){
        comparison++;
        if(arr[i] < arr[pivot]){
            comparison++;

            j++;
            cache = arr[j];
            arr[j] = arr[i];
            arr[i] = cache;
            exchange++;
            assignment+=4;
        }
        i++;
        assignment++;
    }
    cache = arr[j];
    arr[j] = arr[pivot];
    arr[pivot] = cache;
    exchange++;
    *pp = j;
    assignment+=4;
}

void countQuicksort::qsort(int low, int high){
    int pp = 0;
    comparison ++; assignment++;
    if(low >= high) return;

    partition(&pp, low, high);

    qsort(low, pp-1);
    qsort(pp+1, high);
}
