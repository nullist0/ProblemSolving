class countQuicksort{
public:
    int *arr;
    int assignment, comparison, exchange;
    countQuicksort() : assignment(0), comparison(0), exchange(0) {}
    void partition(int*, int, int);
    void qsort(int, int);
};