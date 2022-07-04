#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>

using namespace std;

void parse(int *arr, char *str) {
    char *p;
    int i = 0;

    p = strtok(str, "[,]");
    while(p != NULL) {
        arr[i++] = atoi(p);
        p = strtok(NULL, "[,]");
    }
}

void run(char *p, int *arr, int len) {
    deque<int> deq;
    int rflag = 0;

    for(int i = 0; i < len; i++) {
        deq.push_back(arr[i]);
    }

    while(*p != '\0') {
        if(*p == 'R') {
            rflag = !rflag;
        } else if(*p == 'D') {
            if(deq.empty()){
                printf("error\n");
                return;
            }

            if(rflag) {
                deq.pop_back();
            } else {
                deq.pop_front();
            }
        }
        p++;
    }

    printf("[");
    while(!deq.empty()) {
        if(rflag) {
            printf("%d", deq.back());
            deq.pop_back();
        } else {
            printf("%d", deq.front());
            deq.pop_front();
        }

        if(deq.empty()) {
            break;
        } else {
            printf(",");
        }
    }
    printf("]\n");
}

int main(void) {
    int T;

    scanf("%d", &T);

    while(T--) {
        char p[100001];
        char input[400003];
        
        int arr[100001];
        int n;

        scanf("%s", p);
        scanf("%d", &n);
        scanf("%s", input);

        parse(arr, input);

        run(p, arr, n);
    }

    return 0;
}