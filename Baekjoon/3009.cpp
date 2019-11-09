#include <cstdio>

int main(void){
	int x = 0, y = 0, cx[3], cy[3];
	for(int i = 0; i < 3; i++){
		scanf("%d %d", cx + i, cy + i);
		if(cx[0] == cx[1]) x = cx[2];
		else if(cx[0] == cx[2]) x = cx[1];
		else x = cx[0];
		if(cy[0] == cy[1]) y = cy[2];
		else if(cy[0] == cy[2]) y = cy[1];
		else y = cy[0];
	}
	printf("%d %d\n", x, y);
	return 0;
}
