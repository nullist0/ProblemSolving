#include <cstdio>

int main(void){
	int alpha[26];
	char S[101], i = 0, Si = 0;
	for(i = 0; i < 26; i++) alpha[i] = -1;
	scanf("%s", S);

	i = 0;
	while(S[i]){
		Si = S[i] - 'a';
		if(alpha[Si] < 0)
			alpha[Si] = i;
		i++;
	}

	for(i = 0; i < 26; i++)
		printf("%d ", alpha[i]);
	printf("\n");
	return 0;
}
