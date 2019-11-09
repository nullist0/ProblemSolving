#include <cstdio>

int main(void){
	char S[1000000], Mc = '?';
	int c[26];
	int i, M = 0, MACC = 0;
	scanf("%s", S);
	for(i = 0; i < 26; i++) c[i] = 0;
	for(i = 0; S[i]; i++){
		//printf("[%d]", S[i] - 'a' >= 0 ? S[i] - 'a' : S[i] - 'A');
		c[S[i] - 'a' >= 0 ? S[i] - 'a' : S[i] - 'A']++;
	}
	//printf("\n");
	for(i = 0; i < 26; i++){
		if(c[i] > M){
			M = c[i];
			Mc = 'A' + i;
			MACC = 1;
		}
		else if(c[i] == M) MACC++;
	}

	printf("%c\n", MACC == 1 ? Mc : '?');

	return 0;
}
