#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;

typedef long long ll;
const int NG = 0x3f3f3f3f;

struct Block{
	int r, c, h;
	Block(){} Block(int r, int c, int h):r(r), c(c), h(h){}
	bool operator <(const Block &o)const{
		return h > o.h;
	}
};

ll h[300][300];
int dr[4] = {1, 0, -1, 0}, dc[4] = {0, 1, 0, -1};
bool chk[300][300];

int main()
{
	int R, C; scanf("%d %d", &C, &R);
	priority_queue<Block> q;
	for(int i = 0; i < R; i++)
		for(int j = 0; j < C; j++){
			scanf("%lld", &h[i][j]);
			if(i == 0 || i == R - 1 || j == 0 || j == C - 1){
				q.push(Block(i, j, h[i][j]));
				chk[i][j] = true;
			}
		}

	ll ans = 0;
	while(!q.empty()){
		int r = q.top().r, c = q.top().c, curh = h[r][c]; q.pop();
		for(int i = 0; i < 4; i++){
			int nr = r + dr[i], nc = c + dc[i];
			if(nr < 0 || nc < 0 || nr >= R || nc >= C || chk[nr][nc])
				continue;
			if(h[nr][nc] < curh){
				ans += curh - h[nr][nc];
				h[nr][nc] = curh;
			}
			chk[nr][nc] = true;
			q.push(Block(nr, nc, h[nr][nc]));
		}
	}
	printf("%lld\n", ans);

	return 0;
}
