#include <stdio.h>
#include <queue>
#include <memory.h>
#include <algorithm>
using namespace std;

struct Node{
	int r, c, t;
	Node(int r, int c, int t): r(r), c(c), t(t){}
};

char map[60][61];
bool no[60][60][120];
int R, C, mind[60][61][140];
int dr[5] = {0, 0, 1, 0, -1}, dc[5] = {0, 1, 0, -1, 0};

void block(int r, int c, int k1, int k2, int d){
	bool chk = false;
	for(int add = 0; k1 + add <= 120 || k2 + add <= 120; add += d){
		if(r == 0 && c == 2 && k1 == 4 && k2 == 6 && d == 10) chk = true;
		for(int i = r; i >= 0; i--){
			if(map[i][c] != '.') break;
			no[i][c][k1 + add] = no[i][c][k2 + add] = true;
		}
		for(int i = r; r < R; i++){
			if(map[i][c] != '.') break;
			no[i][c][k1 + add] = no[i][c][k2 + add] = true;
		}
		for(int i = c; i >= 0; i--){
			if(map[r][i] != '.') break;
			no[r][i][k1 + add] = no[r][i][k2 + add] = true;
		}
		for(int i = c; i < C; i++){
			if(map[r][i] != '.') break;
			no[r][i][k1 + add] = no[r][i][k2 + add] = true;
		}
	}
}

int main()
{
	scanf("%d %d", &R, &C);
	int rs, cs, re, ce; scanf(" (%d %d) (%d %d)", &rs, &cs, &re, &ce);
	rs--; cs--; re--; ce--;
	for(int i = 0; i < R; i++)
		scanf("%s", map[i]);

	int P; scanf("%d", &P);
	for(int i = 0, n; i < P; i++){
		scanf("%d", &n);
		for(int j = 0, r, c; j < n; j++){
			scanf(" (%d %d)", &r, &c);
			r--; c--;
			block(r, c, j, 2 * n - 2 - j, max(1, 2 * n - 2));
		}
	}

	memset(mind, 0xff, sizeof(mind));
	queue<Node> q;
	if(!no[rs][cs][0] && !no[rs][cs][0])
		q.push(Node(rs, cs, mind[rs][cs][0] = 0));
	
	while(!q.empty()){
		int r = q.front().r, c = q.front().c, t = q.front().t; q.pop();
		int chkt = (t + 1) % 120;
		for(int i = 0; i < 5; i++){
			int nr = r + dr[i], nc = c + dc[i];
			if(nr < 0 || nc < 0 || nr >= R || nc >= C) continue;
			if(map[nr][nc] != '.') continue;
			if(nr == re && nc == ce) return !printf("%d\n", t + 1);
			if(no[nr][nc][chkt] || mind[nr][nc][chkt] >= 0) continue;
			mind[nr][nc][chkt] = t;
			q.push(Node(nr, nc, t + 1));
		}
	}
	printf("IMPOSSIBLE\n");
	
	return 0;
}
