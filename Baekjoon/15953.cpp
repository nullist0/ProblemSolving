#include <cstdio>

int first[7] = {0, 500, 300, 200, 50, 30, 10};
int second[6][2] = {{0, 0}, {512, 1}, {256, 2}, {128, 4}, {64, 8}, {32, 16}};

int main(void){
	int T, a, b;

	scanf("%d", &T);

	for(int t = 0; t < T; t++){
		int result = 0;
		scanf("%d %d", &a, &b);

		if(a != 0){
			for(int i = 1; i <= 6; i++){
				a -= i;
				if(a <= 0){
					result += first[i];
					break;
				}
			}
		}
		if(b != 0){
			for(int i = 1; i <= 5; i++){
				b -= second[i][1];
				if(b <= 0){
					result += second[i][0];
					break;
				}
			}
		}

		printf("%d\n", result * 10000);
	}

	return 0;
}