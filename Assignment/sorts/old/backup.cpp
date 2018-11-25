#include <cstdio>
#include <ctime>
#include <cstdlib>
#define MAX_SIZE 10000000

class quicksort{
public:
    int arr[MAX_SIZE];
    void partition(int*, int, int);
    void qsort(int, int);
};

class heapsort{
public:
    int *heap, N;
    void hsort(int, int*, int*);
    void makeheap(int);
    void removekeys(int, int, int*);
    int root(int);
    void siftdown(int);
    int getLargeChild(int);
};

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
    // printf("%d %d %d\n", pp, low, high);

    qsort(low, pp-1);
    qsort(pp+1, high);
}

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

void suffle(int n, int *l){
    int r = 0, cache;
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        r = rand() % (i + 1);
        cache = l[i];
        l[i] = l[r];
        l[r] = cache;
    }
}

void settingTest(int n, int *arr){
    for(int i = 0; i < n; i++)
        arr[i] = i;
    suffle(n, arr);
}

int main(void){
    
    heapsort h;
    int n = 1000000;
    int arr[n], ans[n];

    settingTest(n, arr);
    h.hsort(n, arr, ans);

    // for(int i = 0; i < n; i++)
    //     printf("[%d]", ans[i]);
    // printf("\n");

    return 0;
}