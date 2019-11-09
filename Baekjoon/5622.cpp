#include <cstdio>

int main(void){
	char S[16];
	int i, total = 0;
	scanf("%s", S);
	for(i = 0; S[i]; i++){
		if(S[i] == 'Z') S[i] -= 2;
		else if(S[i] >= 'S') S[i]--;
		//printf("[%d]", (S[i]-'A')/3 + 3);
		total += (S[i]-'A')/3 + 3;
	}
	printf("%d\n", total);
	return 0;
}
