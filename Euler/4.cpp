#include <stdio.h>
#include <string.h>

int palin(int nmn){
	char p[15];
	int len;

	sprintf(p, "%d", nmn);
	len = strlen(p);

	for(int i = 0; i < len; i++){
		if(p[i] != p[len - i - 1]) return 0;
	}
	return 1;
}

int main(void){
	int n = 0, m = 0, p, max = 0;
	printf("pp: %d\n", palin(9801));
	
	for(n = 999; n > 99; n --){
		for(m = 999; m > 99; m --){
			p = palin(n * m);
			if(p){
				max = max < n * m ? n * m : max;
				break;
			}
		}
	}
	printf("%d\n", max);
	return 0;
}
