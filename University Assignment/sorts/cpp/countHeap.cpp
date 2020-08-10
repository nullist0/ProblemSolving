#include "../headers/countheap.h"

void countHeapsort::hsort(int n, int *H, int *S){
    heap = H;
    N = n;
    assignment += 2;

    makeheap(n);
    removekeys(n, 0, S);
}

void countHeapsort::makeheap(int n){
    int i = n - 1;
    assignment++;
    while(i >= 0){
        comparison++;
        siftdown(i);
        i--;
        assignment++;
    }
    comparison++;
}

void countHeapsort::removekeys(int n, int H, int *S){
    int i = n - 1;
    assignment++;
    while(i >= 0){
        comparison++;
        S[i] = root(H);
        assignment++;
        i--;
        assignment++;
    }
    comparison++;
}

int countHeapsort::root(int H){
    int key = heap[H];
    N--;
    heap[H] = heap[N];
    assignment += 3;
    siftdown(H);
    return key;
}

void countHeapsort::siftdown(int H){
    int parent, largerchild, cache;
    parent = H;
    largerchild = getLargeChild(parent);
    assignment += 2;

    while(heap[parent] < heap[largerchild]){   
        if(largerchild < 0) break;
        comparison += 2;

        cache = heap[parent];
        heap[parent] = heap[largerchild];
        heap[largerchild] = cache;
        exchange ++;
        assignment += 3;

        parent = largerchild;
        largerchild = getLargeChild(parent);
        assignment += 2;
    }
}

int countHeapsort::getLargeChild(int parent){
    int left = 2 * parent + 1;
    int right = 2 * parent + 2;
    assignment += 2;

    if(left >= N && right >= N){
        comparison += 2;
        return -1;
    }
    else if(left < N && right < N){
        comparison += 5;
        return heap[left] > heap[right] ? left : right;
    }
    else{
        comparison += 5;
        return left < N ? left : right;
    }
}
