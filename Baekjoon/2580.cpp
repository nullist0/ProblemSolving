#include <cstdio>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

int bit[9]={1, 2, 4, 8, 16, 32, 64, 128, 256};
int solved = 511;
int map[9][9];
int row[9];
int column[9];
int cell[9];

vector<pair<int, int> > tosolve;

int cellIndex(int y, int x){
	return y/3 *3 + x/3;
}

int isSolved(){
	
	for(int i = 0; i < 9; i++){
		if(row[i] == solved && column[i] == solved && cell[i] == solved)
			continue;
		else return 0;
	}
	
	return 1;
}

void find(int index){
	if(index >= tosolve.size()) return;
	int y = tosolve[index].first;
	int x = tosolve[index].second;
	int cIndex = cellIndex(y, x);
	int mask = row[y] | column[x] | cell[cIndex];
	
	for(int i = 0; i < 9; i++){
		if((mask & bit[i]) == 0){
			map[y][x] = i+1;

			row[y] += bit[i];
			column[x] += bit[i];
			cell[cIndex] += bit[i];
			
			find(index+1);
			
			if(isSolved())
				break;

			map[y][x] = 0;
			
			row[y] -= bit[i];
			column[x] -= bit[i];
			cell[cIndex]-= bit[i];
		}
	}
}

int main(void){
	for(int y = 0; y < 9; y++){
		for(int x = 0; x < 9; x++){
			//printf("%d ", y/3 *3 + x/3);
			scanf("%d", &map[y][x]);
			if(map[y][x] == 0)
				tosolve.push_back(make_pair(y, x));
		}
		//printf("\n");
	}
	
	for(int y = 0; y < 9; y++){
		for(int x = 0; x < 9; x++){
			if(map[y][x] == 0) continue;
			row[y] += bit[map[y][x]-1];
			column[x] += bit[map[y][x]-1];
			cell[cellIndex(y, x)] += bit[map[y][x]-1];
		}
	}
	
	find(0);
	
	for(int y = 0; y < 9; y++){
		for(int x = 0; x < 9; x++){
			printf("%d ", map[y][x]);
		}
		printf("\n");
	}
	
	return 0;
}