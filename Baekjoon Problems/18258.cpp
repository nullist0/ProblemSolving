#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;

queue<int> q;

int main(void) {    
    char command[10];
    int argument;

    int N;

    scanf("%d", &N);

    while(N--) {
        scanf("%s", command);

        if(strcmp(command, "push") == 0) {
            scanf("%d", &argument);

            q.push(argument);
        } else if(strcmp(command, "pop") == 0) {
            printf("%d\n", q.empty() ? -1 : q.front());
            if(!q.empty()) q.pop();
        } else if(strcmp(command, "size") == 0) {
            printf("%ld\n", q.size());
        } else if(strcmp(command, "empty") == 0) {
            printf("%d\n", q.empty());
        } else if(strcmp(command, "front") == 0) {
            printf("%d\n", q.empty() ? -1 : q.front());
        } else if(strcmp(command, "back") == 0) {
            printf("%d\n", q.empty() ? -1 : q.back());
        }
    }

    return 0;
}