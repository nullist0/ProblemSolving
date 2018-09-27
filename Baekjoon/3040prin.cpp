#include <stdio.h>

int main(void){
	int cap[9], ex[2] = {-1, -1}, i, j, sum = 0;
	for(i = 0; i < 9; i ++){
		scanf("%d", cap + i);
		sum += cap[i];
	}

	for(i = 0; i < 9; i++){
		for(j = 0; j < 9; j++){
			if(i == j) continue;
			if(sum - cap[i] - cap[j] == 100){
				ex[0] = i;
				ex[1] = j;
				break;
			}
		}
		if(ex[0] >= 0) break;
	}

	for(i = 0; i < 9; i++)
		if(i != ex[0] && i != ex[1])
			printf("%d\n", cap[i]);

	return 0;
}