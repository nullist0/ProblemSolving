#include <cstdio>

int group(char *S){
	int alpha[26];
	for(int j = 0; j < 26; j++) alpha[j] = 0;
	for(int j = 1; S[j]; j++){
		if(S[j-1] != S[j]) alpha[S[j] - 'a']++;
		if(S[j] != S[j+1]) alpha[S[j] - 'a']++;
		if(alpha[S[j] - 'a'] > 2) return 0;
	}
	return 1;
}

int main(void){
	char S[102];
	int N = 0, W = 0;

	scanf("%d" ,&N);
	S[0] = ' ';
	for(int i = 0; i < N; i++){
		scanf("%s", S + 1);
		W += group(S);
	}
	printf("%d\n", W);
	return 0;
}
