#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int map[101][101];
int n, m;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int bfs(int sx, int sy){
    queue<pair<int, int> > q;
    int xMin = n, xMax = 0;
    int yMin = m, yMax = 0;
    int x, y, nx, ny, count = 0;
    q.push(make_pair(sx, sy));

    map[sx][sy] = 1;
    while(!q.empty()){
        x = q.front().first; y = q.front().second;
        q.pop();
        count++;

        if(xMin > x) xMin = x;
        if(xMax < x) xMax = x;
        if(yMin > y) yMin = y;
        if(yMax < y) yMax = y;

        //put to queue
        for(int i = 0; i < 4; i++){
            nx = x + dir[i][0]; ny = y + dir[i][1];
            if((0 <= nx && nx < n) && (0 <= ny && ny < m)){
                if(map[nx][ny] == 0) {
                    map[nx][ny] = 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
    return ((xMax - xMin + 1) * (yMax - yMin + 1)) == count;
}

int main(void){
    int area = 0, rect = 0;

    scanf("%d %d", &n, &m);
    for(int x = 0; x < n; x++)
        for(int y = 0; y < m; y++)
            scanf("%d", &map[x][y]);

    for(int x = 0; x < n; x++){
        for(int y = 0; y < m; y++){
            if(map[x][y] == 0){
                area++;
                rect += bfs(x, y);
            }
        }
    }

    printf("%d %d\n", area, rect);

    return 0;
}