// solution:
// 메테오의 범위가 300까지지 피하기 위해서는 301 좌표로도 갈 수 있음
// 탐색이 끝난 후 아직 처리하지 않은 메테오 처리해줄것.

// 시간복잡도: O(maxR * maxC)
// 분류: BFS
// 난이도: 1500

#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

struct Crd{ int r, c; };
queue<Crd> tm[1001];

int map[302][302], dr[] = {0, 1, 0, -1}, dc[] = {1, 0, -1, 0};

int main()
{
	int N; scanf("%d", &N);
	for(int i = 0, r, c, t; i < N; i++){
		scanf("%d %d %d", &r, &c, &t);
		tm[t].push({r, c});
	}

	queue<Crd> q; q.push({0, 0});
	map[0][0] = 1;
	while(!q.empty()){
		int r = q.front().r, c = q.front().c, t = map[r][c] - 1; q.pop();
		while(!tm[t].empty()){
			int mr = tm[t].front().r, mc = tm[t].front().c; tm[t].pop();
			map[mr][mc] = -1;
			for(int i = 0; i < 4; i++){
				int nr = mr + dr[i], nc = mc + dc[i];
				if(nr < 0 || nc < 0) continue;
				map[nr][nc] = -1;
			}
		}
		if(map[r][c] < 0) continue;

		for(int i = 0; i < 4; i++){
			int nr = r + dr[i], nc = c + dc[i];
			if(nr < 0 || nc < 0|| nr > 301 || nc > 301) continue;
			if(!map[nr][nc]){
				map[nr][nc] = map[r][c] + 1;
				q.push({nr, nc});
			}
		}
	}

	for(int t = 0; t <= 1000; t++)
		while(!tm[t].empty()){
			int mr = tm[t].front().r, mc = tm[t].front().c; tm[t].pop();
			map[mr][mc] = -1;
			for(int i = 0; i < 4; i++){
				int nr = mr + dr[i], nc = mc + dc[i];
				if(nr < 0 || nc < 0) continue;
				map[nr][nc] = -1;
			}
		}

	int ans = 0x3f3f3f3f;
	for(int i = 0; i <= 301; i++)
		for(int j = 0; j <= 301; j++)
			if(map[i][j] > 1) ans = min(ans, map[i][j]);
	printf("%d\n", ans == 0x3f3f3f3f ? -1 : ans - 1);

	return 0;
}