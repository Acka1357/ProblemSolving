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
#include <assert.h>
using namespace std;

struct Status{
	int idx, cur, r, c, change;
	Status(int i, int cur, int r, int c, int ch):idx(i), cur(cur), r(r), c(c), change(ch){}
	bool operator <(const Status &o)const{
		return change == o.change ? idx < o.idx : change < o.change;
	}
};

int dr[8] = {-1, -2, -1, -2, 1, 2, 1, 2};
int dc[8] = {2, 1, -2, -1, 2, 1, -2, -1};
int ddr[2][4] = {{-1, 0, 1, 0}, {-1, 1, -1, 1}}, ddc[2][4] = {{0, 1, 0, -1}, {-1, -1, 1, 1}};
int ir[101], ic[101];
bool chk[101][3][10][10];

int main()
{
	int N; scanf("%d", &N);
	for(int i = 0, x; i < N; i++)
		for(int j = 0; j < N; j++){
			scanf("%d", &x);
			ir[--x] = i; ic[x] = j;
		}

	int last = N * N;
	vector<Status> q[222];
	q[0].push_back(Status(1, 0, ir[0], ic[0], 0));
	q[0].push_back(Status(1, 1, ir[0], ic[0], 0));
	q[0].push_back(Status(1, 2, ir[0], ic[0], 0));
	chk[1][0][ir[0]][ic[0]] = chk[1][1][ir[0]][ic[0]] = chk[1][2][ir[0]][ic[0]] = true;
	for(int st = 1; st < 222; st++){
		sort(q[st - 1].begin(), q[st - 1].end());
		int l = 0;
		for(int i = 0; i < q[st - 1].size(); i++){
			if(i && q[st - 1][i].change != q[st - 1][i - 1].change){
				for(; l < i; l++){
					int &idx = q[st - 1][l].idx, &cur = q[st - 1][l].cur, &r = q[st - 1][l].r, &c = q[st - 1][l].c, &change = q[st - 1][l].change;					
					for(int nxt = 0; nxt < 3; nxt++)
						if(!chk[idx][nxt][r][c]){
							q[st].push_back(Status(idx, nxt, r, c, change + 1));
							chk[idx][nxt][r][c] = true;
						}
				} 
			}
			int &idx = q[st - 1][i].idx, &cur = q[st - 1][i].cur, &r = q[st - 1][i].r, &c = q[st - 1][i].c, &change = q[st - 1][i].change;
			// printf("[%d] %d: %d %d %d %d\n", st, idx, cur, r + 1, c + 1, change);
			if(idx == last) return !printf("%d %d\n", st - 1, change);
			if(cur == 0){
				for(int i = 0; i < 8; i++){
					int nr = r + dr[i], nc = c + dc[i];
					if(nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
					if(chk[idx][cur][nr][nc]) continue;
					chk[idx][cur][nr][nc] = true;
					q[st].push_back(Status(idx, cur, nr, nc, change));
					if(nr == ir[idx] && nc == ic[idx]){
						if(chk[idx + 1][cur][nc][nc]) continue;
						q[st].push_back(Status(idx + 1, cur, nr, nc, change));
						chk[idx + 1][cur][nr][nc] = true;
					}
				}
			}
			else{
				for(int d = 0; d < 4; d++){
					int addr = ddr[cur - 1][d], addc = ddc[cur - 1][d];
					for(int nr = r + addr, nc = c + addc; nr >= 0 && nc >= 0 && nr < N && nc < N; nr += addr, nc += addc){
						if(chk[idx][cur][nr][nc]) continue;
						chk[idx][cur][nr][nc] = true;
						q[st].push_back(Status(idx, cur, nr, nc, change));
						if(nr == ir[idx] && nc == ic[idx]){
							if(chk[idx + 1][cur][nc][nc]) continue;
							q[st].push_back(Status(idx + 1, cur, nr, nc, change));
							chk[idx + 1][cur][nr][nc] = true;
						}
					}
				}
			}
		}
		for(; l < q[st - 1].size(); l++){
			int &idx = q[st - 1][l].idx, &cur = q[st - 1][l].cur, &r = q[st - 1][l].r, &c = q[st - 1][l].c, &change = q[st - 1][l].change;					
			for(int nxt = 0; nxt < 3; nxt++)
				if(!chk[idx][nxt][r][c]){
					q[st].push_back(Status(idx, nxt, r, c, change + 1));
					chk[idx][nxt][r][c] = true;
				}
		} 
	}
	assert(false);
	return 0;
}
