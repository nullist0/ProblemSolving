
#include <cstdio>
#include <chrono>

#include <ctime>
#include <cstdlib>
#include "../headers/heap.h"
#include "../headers/quick.h"

#include "../headers/countheap.h"
#include "../headers/countquick.h"

using namespace std;
using namespace std::chrono;

void shuffle(int n, int *l){
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
        arr[i] = i+1;
    shuffle(n, arr);
}

void measureTime(int n, int* res){
    heapsort h;
    quicksort q;
    system_clock::time_point start_quick, end_quick, start_heap, end_heap;
    nanoseconds qtime, htime;
    int q_arr[n], h_arr[n], ans[n], cache = 0;

    settingTest(n, q_arr);
    for(int i = 0; i < n; i++) h_arr[i] = q_arr[i];
    q.arr = q_arr;

    start_quick = system_clock::now();
    q.qsort(0, n-1);
    end_quick = system_clock::now();

    start_heap = system_clock::now();
    h.hsort(n, h_arr, ans);
    end_heap = system_clock::now();

    for(int i = 0; i < n-1; i++){
        cache += !(ans[i] < ans[i+1]);
        cache += !(q_arr[i] < q_arr[i+1]);
    }

    qtime = duration_cast<nanoseconds>(end_quick - start_quick);
    htime = duration_cast<nanoseconds>(end_heap - start_heap);

    if(cache == 0){
        printf("Sorted\n");
        printf("Quick\t%lu ns\n",   qtime.count());
        printf("Heap\t%lu ns\n",    htime.count());
        res[0] = qtime.count();
        res[1] = htime.count();
    }
}

void measureOperation(int n, int res[2][3]){
    countHeapsort h;
    countQuicksort q;
    int q_arr[n], h_arr[n], ans[n], cache = 0;

    settingTest(n, q_arr);
    for(int i = 0; i < n; i++) h_arr[i] = q_arr[i];
    q.arr = q_arr;

    q.qsort(0, n-1);
    h.hsort(n, h_arr, ans);

    for(int i = 0; i < n-1; i++){
        cache += !(ans[i] < ans[i+1]);
        cache += !(q_arr[i] < q_arr[i+1]);
    }

    if(cache == 0){
        printf("Sorted\n");
        printf("Quick\tComparison : %d, Assginment : %d, Exchange : %d\n", q.comparison, q.assignment, q.exchange);
        printf("Heap\tComparison : %d, Assginment : %d, Exchange : %d\n",  h.comparison, h.assignment, h.exchange);

        res[0][0] = q.comparison;
        res[0][1] = q.assignment;
        res[0][2] = q.exchange;

        res[1][0] = h.comparison;
        res[1][1] = h.assignment;
        res[1][2] = h.exchange;
    }
}

void testingTime(int start, int end, int step){
    int res[2];
    for(int ln = start; ln <= end; ln+=step){
        printf("N = %d\n", ln);
        measureTime(ln, res);
    }
}

void testingOperation(int start, int end, int step){
    int res[2][3];
    for(int ln = start; ln <= end; ln+=step){
        printf("N = %d\n", ln);
        measureOperation(ln, res);
    }
}

void testingPTime(int start, int end, int step){
    int res[2];
    for(int ln = start; ln <= end; ln+=step){
        printf("N = %d\n", ln);
        measureTime(ln, res);
        printf("quick/heap = %.2lf\n", (double)res[0]/res[1]);
    }
}

void testingPOperation(int start, int end, int step){
    int res[2][3];
    for(int ln = start; ln <= end; ln+=step){
        printf("N = %d\n", ln);
        measureOperation(ln, res);
        printf("comparison, quick/heap = %.2lf\n", (double)res[0][0]/res[1][0]);
        printf("assignment, quick/heap = %.2lf\n", (double)res[0][1]/res[1][1]);
        printf("  exchange, quick/heap = %.2lf\n", (double)res[0][2]/res[1][2]);
    }
}

int main(void){
    //testingPTime(100, 10000, 100);
    testingPOperation(100, 10000, 100);
    return 0;
}