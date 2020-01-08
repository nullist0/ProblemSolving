#include <cstdio>
#include <algorithm>
#include <cstring>
#include <functional>
#include <vector>

using namespace std;

int main(void){
    char input[11];
    scanf("%s", input);

    sort(input, input + strlen(input), greater<int>());

    printf("%s\n", input);

    return 0;
}