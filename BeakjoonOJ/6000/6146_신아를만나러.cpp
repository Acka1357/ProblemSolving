#include <cstdio>
#include <queue>
using namespace std;

struct Crd{ int x, y; };

int d[1001][1001], dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

int main()
{
	int X, Y, N; scanf("%d %d %d", &X, &Y, &N);
	X += 500; Y += 500;
	for(int i = 0, x, y; i < N; i++){
		scanf("%d %d", &x, &y);
		d[x + 500][y + 500] = -1;
	}

	queue<Crd> q; q.push({500, 500});
	d[500][500] = 1;
	while(!q.empty()){
		int x = q.front().x, y = q.front().y; q.pop();
		if(x == X && y == Y) return !printf("%d\n", d[x][y] - 1);
		for(int i = 0; i < 4; i++){
			int nx = x + dx[i], ny = y + dy[i];
			if(nx < 0 || ny < 0 || nx > 1000 || ny > 1000) continue;
			if(!d[nx][ny]){
				q.push({nx, ny});
				d[nx][ny] = d[x][y] + 1;
			}
		}
	}
	printf("-1\n");

	return 0;
}
