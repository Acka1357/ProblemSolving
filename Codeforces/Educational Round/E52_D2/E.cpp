#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <memory.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stack>
#include <utility>
using namespace std;

struct Status{
	int idx, cur, r, c, step, change;
	Status(int i, int cur, int r, int c, int s, int ch):idx(i), cur(cur), r(r), c(c), step(s), change(ch){}
	bool operator <(const Status &o)const{
		return step == o.step ? change > o.change : step > o.step;
	}
};

int dr[8] = {-1, -2, -1, -2, 1, 2, 1, 2};
int dc[8] = {2, 1, -2, -1, 2, 1, -2, -1};
int ddr[2][4] = {{-1, 0, 1, 0}, {-1, 1, -1, 1}}, ddc[2][4] = {{0, 1, 0, -1}, {-1, -1, 1, 1}};
int ir[100], ic[100];
int chks[100][3][10][10], chkc[100][3][10][10];

int main()
{
	int N; scanf("%d", &N);
	for(int i = 0, x; i < N; i++)
		for(int j = 0; j < N; j++){
			scanf("%d", &x);
			ir[--x] = i; ic[x] = j;
		}

	memset(chks, 0x3f, sizeof(chks));
	memset(chkc, 0x3f, sizeof(chkc));
	int last = N * N;
	priority_queue<Status> q;
	q.push(Status(1, 0, ir[0], ic[0], 0, 0));
	q.push(Status(1, 1, ir[0], ic[0], 0, 0));
	q.push(Status(1, 2, ir[0], ic[0], 0, 0));
	chks[1][0][ir[0]][ic[0]] = chks[1][1][ir[0]][ic[0]] = chks[1][2][ir[0]][ic[0]] = 0;
	chkc[1][0][ir[0]][ic[0]] = chkc[1][1][ir[0]][ic[0]] = chkc[1][2][ir[0]][ic[0]] = 0;
	while(!q.empty()){
		int idx = q.top().idx, cur = q.top().cur, r = q.top().r, c = q.top().c, step = q.top().step, change = q.top().change; q.pop();
		if(idx == last) return !printf("%d %d\n", step, change);
		if(chks[idx][cur][r][c] < step || (chks[idx][cur][r][c] == step && chkc[idx][cur][r][c] < change)) continue;
		for(int nxt = 0; nxt < 3; nxt++)
			if(chks[idx][nxt][r][c] > step + 1 || (chks[idx][nxt][r][c] == step + 1 && chkc[idx][nxt][r][c] > change + 1)){
				q.push(Status(idx, nxt, r, c, step + 1, change + 1));
				chks[idx][nxt][r][c] = step + 1;
				chkc[idx][nxt][r][c] = change + 1;
			}

		if(cur == 0){
			for(int i = 0; i < 8; i++){
				int nr = r + dr[i], nc = c + dc[i];
				if(nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
				if(nr == ir[idx] && nc == ic[idx]){
					if(chks[idx + 1][cur][nr][nc] < step + 1 || (chks[idx + 1][cur][nr][nc] == step + 1 && chkc[idx + 1][cur][nr][nc] <= change));
					else {
						q.push(Status(idx + 1, cur, nr, nc, step + 1, change));
						chks[idx + 1][cur][nr][nc] = step + 1;
						chkc[idx + 1][cur][nr][nc] = change;
					}
				}
				if(chks[idx][cur][nr][nc] < step + 1 || (chks[idx][cur][nr][nc] == step + 1 && chkc[idx][cur][nr][nc] <= change)) continue;
				q.push(Status(idx, cur, nr, nc, step + 1, change));
				chks[idx][cur][nr][nc] = step + 1;
				chkc[idx][cur][nr][nc] = change;
			}
			continue;
		}
		for(int d = 0; d < 4; d++){
			int addr = ddr[cur - 1][d], addc = ddc[cur - 1][d];
			for(int nr = r + addr, nc = c + addc; nr >= 0 && nc >= 0 && nr < N && nc < N; nr += addr, nc += addc){
				if(nr == ir[idx] && nc == ic[idx]){
					if(chks[idx + 1][cur][nr][nc] < step + 1 || (chks[idx + 1][cur][nr][nc] == step + 1 && chkc[idx + 1][cur][nr][nc] <= change));
					else{
						q.push(Status(idx + 1, cur, nr, nc, step + 1, change));
						chks[idx + 1][cur][nr][nc] = step + 1;
						chkc[idx + 1][cur][nr][nc] = change;
					}
				}
				if(chks[idx][cur][nr][nc] < step + 1 || (chks[idx][cur][nr][nc] == step + 1 && chkc[idx][cur][nr][nc] <= change)) continue;
				q.push(Status(idx, cur, nr, nc, step + 1, change));
				chks[idx][cur][nr][nc] = step + 1;
				chkc[idx][cur][nr][nc] = change;
			}
		}
	}

	return 0;
}