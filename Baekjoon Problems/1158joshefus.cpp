#include <cstdio>
#include <queue>

using namespace std;

int main(){
	int n = 0, m = 0;

	scanf("%d %d", &n, &m);

	queue<int> in, out;
	int count = 0;

	for(int i = 0; i < n; i++)
		in.push(i+1);


	for (int i = 1; count < n; i++)
	{
		int t = in.front();
		in.pop();

		if(i % m != 0){
			out.push(t);
		}else{
			if(count == 0)
				printf("<");

			
			if(count == n-1){
				printf("%d",t);
				printf(">");
			}else{
				printf("%d, ",t);
			}
			count++;
		}

		if(in.empty()){
			while(!out.empty()){
				int s = out.front();
				in.push(s);
				out.pop();
			}
		}
	}
	printf("\n");
}