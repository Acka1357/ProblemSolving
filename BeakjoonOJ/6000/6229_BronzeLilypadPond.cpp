#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

struct Crd{ int r, c; };

int R, C, M1, M2, map[30][30], dist[30][30];
int dr[4] = {1, 1, -1, -1}, dc[4] = {1, -1, 1, -1};

int main()
{
	scanf("%d %d %d %d", &R, &C, &M1, &M2);

	queue<Crd> q;
	for(int i = 0; i < R; i++)
		for(int j = 0; j < C; j++){
			scanf("%d", &map[i][j]);
			if(map[i][j] == 3){
				q.push({i, j});
				dist[i][j] = 1;
			}
		}

	while(!q.empty()){
		int r = q.front().r, c = q.front().c; q.pop();
		if(map[r][c] == 4) return !printf("%d\n", dist[r][c] - 1);
		for(int d = 0; d < 4; d++){
			int nrs[2] = {r + dr[d] * M1, r + dr[d] * M2};
			int ncs[2] = {c + dc[d] * M2, c + dc[d] * M1};
			for(int i = 0; i < 2; i++){
				int nr = nrs[i], nc = ncs[i];
				if(nr < 0 || nc < 0 || nr >= R || nc >= C) continue;
				if(dist[nr][nc] || map[nr][nc] == 0 || map[nr][nc] == 2) continue;
				dist[nr][nc] = dist[r][c] + 1;
				q.push({nr, nc});
			}
		}
	}

	return !printf("-1\n");
}
