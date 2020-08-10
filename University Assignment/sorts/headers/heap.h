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