#include <cstdio>
#define MAX 100

int N;
int arr[MAX];
int current[MAX];
int composed[MAX];

int solution_count = 0;
int solution[MAX];

int verify() {
	for(int i = 0; i < N; i++) {
		if(composed[i] != current[i]){
			return 0;
		}
	}
	return 1;
}

void select(int num, int count) {
	current[num] = 1;
	composed[arr[num]] = 1;

	if(!verify()){
		return;
	}
	else{
		solution_count = count;
		for(int i = 0; i < N; i++){
			solution[i] = current[i];
		}
	}

	for(int i = num + 1; i < N; i++){
		select(i, count + 1);
		current[i] = 0;
		composed[arr[i]] = 0;
	}
}

int main(void) {
	scanf("%d", &N);

	for(int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		arr[i] -= 1;
	}

	select(0, 0);

	printf("%d\n", solution_count);
	for(int i = 0; i < N; i++){
		if(current[i] == 1){
			printf("%d\n", i);
		}
	}

	return 0;
}