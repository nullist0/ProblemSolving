#include "../headers/heap.h"

void heapsort::hsort(int n, int *H, int *S){
    heap = H;
    N = n;
    makeheap(n);
    removekeys(n, 0, S);
}

void heapsort::makeheap(int n){
    for(int i = n-1; i >= 0; i--)
        siftdown(i);
}

void heapsort::removekeys(int n, int H, int *S){
    for(int i = n-1; i >= 0; i--)
        S[i] = root(H);
}

int heapsort::root(int H){
    int key = heap[H];
    N--;
    heap[H] = heap[N];
    siftdown(H);
    return key;
}

void heapsort::siftdown(int H){
    int parent, largerchild, cache;
    parent = H;
    largerchild = getLargeChild(parent);

    while(heap[parent] < heap[largerchild]){    
        if(largerchild < 0) break;

        cache = heap[parent];
        heap[parent] = heap[largerchild];
        heap[largerchild] = cache;

        parent = largerchild;
        largerchild = getLargeChild(parent);
    }
}

int heapsort::getLargeChild(int parent){
    int left = 2 * parent + 1;
    int right = 2 * parent + 2;
    if(left >= N && right >= N)
        return -1;
    else if(left < N && right < N)
        return heap[left] > heap[right] ? left : right;
    else
        return left < N ? left : right;
}
