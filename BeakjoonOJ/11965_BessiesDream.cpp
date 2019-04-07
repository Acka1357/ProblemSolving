#include <stdio.h>
#include <queue>
using namespace std;

struct Info{
	int r, c, s, d, step;
	Info(int r, int c, int s, int d, int step):r(r), c(c), s(s), d(d), step(step) {}
};

int dr[4] = {0, 1, 0, -1}, dc[4] = {1, 0, -1, 0};
int map[1000][1000];
bool chks[1000][1000][2], chkd[1000][1000][4];

int main()
{
	int N, M; scanf("%d %d", &N, &M);
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
			scanf("%d", &map[i][j]);

	queue<Info> q;
	q.push(Info(0, 0, 0, -1, 0));
	chks[0][0][0] = true;
	while(!q.empty()){
		int r = q.front().r, c = q.front().c, s = q.front().s, d = q.front().d, step = q.front().step; q.pop();
		if(r == N - 1 && c == M - 1) return 0 & printf("%d\n", step);
		
		bool pass = false;
		if(map[r][c] == 4){
			pass = true; s = 0;
			int nr = r + dr[d], nc = c + dc[d];
			if(nr < 0 || nc < 0 || nr >= N || nc >= M) pass = false;
			if(map[nr][nc] == 0 || map[nr][nc] == 3) pass = false;
			if(pass && !chkd[nr][nc][d]){
				chkd[nr][nc][d] = true;
				q.push(Info(nr, nc, 0, d, step + 1));
			}
		}

		if(pass) continue;
		for(int i = 0; i < 4; i++){
			int nr = r + dr[i], nc = c + dc[i];
			if(nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
			if(map[nr][nc] == 0 || (!s && map[nr][nc] == 3)) continue;
			if(!chks[nr][nc][s] && (map[nr][nc] == 1 || (map[nr][nc] == 3 && s))){
				chks[nr][nc][s] = true;
				q.push(Info(nr, nc, s, d, step + 1));
			}
			if(map[nr][nc] == 2 && !chks[nr][nc][1]){
				chks[nr][nc][1] = true;
				q.push(Info(nr, nc, 1, d, step + 1));
			}
			if(map[nr][nc] == 4 && !chkd[nr][nc][i]){
				chkd[nr][nc][i] = true;
				q.push(Info(nr, nc, 0, i, step + 1));
			}
		}
	}

	printf("-1\n");
	return 0;
}