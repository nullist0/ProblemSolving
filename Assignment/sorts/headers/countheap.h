class countHeapsort{
public:
    countHeapsort() : comparison(0), assignment(0){}
    int *heap, N;
    int comparison, assignment;
    void hsort(int, int*, int*);
    void makeheap(int);
    void removekeys(int, int, int*);
    int root(int);
    void siftdown(int);
    int getLargeChild(int);
};