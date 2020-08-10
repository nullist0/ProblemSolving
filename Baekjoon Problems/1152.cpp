#include <cstdio>
#include <ctype.h>

int main(void){
	char S[1000002];
	int i = 0, ret = 0;
	S[0] = ' ';

	fgets(S + 1, sizeof(char) * 1000000, stdin);
	while(S[i]){
		//printf("%c", S[i]);
		if(S[i] == ' ' && S[i+1] != '\0' && isalpha(S[i+1]))
			ret++;
		i++;
	}
	//printf("\n");
	printf("%d\n", ret);
	return 0;
}
