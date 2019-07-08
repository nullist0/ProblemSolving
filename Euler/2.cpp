#include <cstdio>

#define MAX 4000000 // 4 million

int main(void){
	int p1 = 1, p2 = 1, p;
	int total;

	while((p = p1 + p2) < MAX){
		if(p % 2 == 0) printf(" %d ", p), total += p;
		p1 = p2;
		p2 = p;
	}	
	printf("\n%d\n", total);

	return 0;
}
