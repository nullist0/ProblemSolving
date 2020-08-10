#include <stdio.h>
#include <queue>

using namespace std;

int main(void){

	int n, m, tmp;
	queue<int> q;

	scanf("%d %d", &n, &m);

	for(int i = 1; i <= n; i++)
		q.push(i);

	printf("<");
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < m-1; j++){
			tmp = q.front();
			q.pop();
			q.push(tmp);
		}
		printf("%d", q.front());
		q.pop();
		if(i != n)
			printf(", ");
	}

	printf(">\n");

	return 0;
}