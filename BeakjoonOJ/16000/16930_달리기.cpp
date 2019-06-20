// solution:
// mind[i][j][d]: (i, j)를 d방향으로 진행중일때 남은 (최소 시간, 최대 남은 직진칸 수)
// 현재 시간과 같은 시간을 가지는 노드들을 저장하는 큐와,
// 방향을 꺾거나 직진칸 수가 남지 않아 시간이 하나 추가로 드는 다음 큐 2개를 관리하며
// BFS를 진행. 현재 큐가 빌때마다 다음 큐에서 다시 시작.
// * 다른사람들 코드를 보니 격자 그래프 특성으로 인해 방향 상관 없이 먼저 도착한 상태만 가지고 BFS 가능
// 각 정점에서 갈 수 있는 K개를 업데이트 하되 먼저 들린 노드에서 break하는 방식이 훨씬 빠르게 동작함.

// 시간복잡도: O(NM), 상수가 8 이상으로 붙음
// 분류: BFS, Shortest Path
// 난이도: 1750 ~ 2000

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

struct Status{ 
	int step, rem;
	bool operator <(const Status &o)const{
		return step == o.step ? rem > o.rem : step < o.step;
	}
};
struct Crd{ int r, c, dir; Status st; };

char map[1000][1001];
Status mind[1000][1000][4];
int dr[] = {0, 1, 0, -1}, dc[] = {1, 0, -1, 0};

int main()
{
	int R, C, K; scanf("%d %d %d", &R, &C, &K);
	for(int i = 0; i < R; i++)
		scanf("%s", map[i]);

	int sr, sc, er, ec; scanf("%d %d %d %d", &sr, &sc, &er, &ec);
	--sr, --sc, --er, --ec;
	memset(mind, 0x3f, sizeof(mind));
	queue<Crd> q, nq;
	for(int i = 0; i < 4; i++)
		q.push({sr, sc, i, mind[sr][sc][i] = {0, 0}});

	while(!q.empty()){
		int r = q.front().r, c = q.front().c, dir = q.front().dir; 
		Status st = q.front().st; q.pop();
		if(r == er && c == ec) return !printf("%d\n", mind[r][c][dir].step);
		if(mind[r][c][dir] < st) continue;
		for(int i = 0; i < 4; i++){
			int nr = r + dr[i], nc = c + dc[i];
			if(nr < 0 || nc < 0|| nr >= R || nc >= C) continue;
			if(map[nr][nc] == '#') continue;
			if(i == dir && mind[r][c][i].rem){
				Status nxt({mind[r][c][dir].step, mind[r][c][dir].rem - 1});
				if(nxt.step < mind[nr][nc][i].step)
					q.push({nr, nc, i, nxt});
				if(nxt < mind[nr][nc][i]) 
					mind[nr][nc][i] = nxt;
			}
			else{
				Status nxt({mind[r][c][dir].step + 1, K - 1});
				if(nxt.step < mind[nr][nc][i].step)
					nq.push({nr, nc, i, nxt});
				if(nxt < mind[nr][nc][i])
					mind[nr][nc][i] = nxt;
			}
		}
		if(q.empty()) swap(q, nq);
	}
	printf("-1\n");

	return 0;
}
