#include <cstdio>
#include <cstring>

char cro[][4] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

int main(void){
	char S[101], *p;
	int W = 0, i = 0, j = 0, l;

	scanf("%s", S);
	
	while(i < 8){
		l = strlen(cro[i]);
		while(p = strstr(S, cro[i])){
			for(j = 0; j < l; j++)
				p[j] = ' ';
			*p = 'a';
		}
		i++;
	}
	
	i = 0;
	while(S[i]){
		if(S[i] != ' ') W++;
		i++;
	}

	printf("%d\n", W);
	return 0;
}
