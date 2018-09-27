#include <cstdio>

int tree[1500];

int num = 1;

void inorder(int root){
	if(root > num) return;

	inorder(root * 2);
	scanf("%d", tree[root]);
	inorder(root * 2 + 1);
}

int main(){

	int K;
	scanf("%d", &K);

	for(int i = 0; i < K; i++){
		num*=2;
	}
	num--;
	inorder(1);

	int X = 1;
	for(int i = 1; i <= num; i++){
		printf("%d ", tree[i]);
		if(i == X){
			printf("\n");
			X = (X+1) * 2 - 1;
		}
	}
}