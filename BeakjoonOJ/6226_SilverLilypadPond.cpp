#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;

typedef long long ll;

struct Status{ 
	int need, step; ll cnt; 
	bool operator <(const Status &o)const{
		return tie(need, step) < tie(o.need, o.step);
	}
};

struct Crd{
	int r, c; Status st;	
	bool operator <(const Crd &o)const{
		return o.st < st;
	}
};

int R, C, map[30][30];
int dr[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dc[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
Status st[30][30];

int main()
{
	scanf("%d %d", &R, &C);
	memset(st, 0x3f, sizeof(st));

	priority_queue<Crd> q;
	for(int i = 0; i < R; i++)
		for(int j = 0; j < C; j++){
			scanf("%d", &map[i][j]);
			st[i][j].cnt = 0;
			if(map[i][j] == 3){
				q.push({i, j, {0, 0, 1}});
				st[i][j] = {0, 0, 1};
			}
		}

	while(!q.empty()){
		int r = q.top().r, c = q.top().c, need = q.top().st.need, step = q.top().st.step;
		ll cnt = q.top().st.cnt; q.pop();
		if(map[r][c] == 4) return !printf("%d\n%d\n%lld\n", st[r][c].need, st[r][c].step, st[r][c].cnt);
		for(int i = 0; i < 8; i++){
			int nr = r + dr[i], nc = c + dc[i];
			if(nr < 0 || nc < 0 || nr >= R || nc >= C) continue;
			Status nxt{need + (map[nr][nc] == 0), step + 1, 0};
			if(map[nr][nc] == 2 || st[nr][nc] < nxt) continue;
			if(nxt < st[nr][nc]){
				st[nr][nc].cnt = 0;
				q.push({nr, nc, nxt});
			}
			st[nr][nc].need = nxt.need;
			st[nr][nc].step = nxt.step;
			st[nr][nc].cnt += st[r][c].cnt;
		}
	}

	return !printf("-1\n");
}
