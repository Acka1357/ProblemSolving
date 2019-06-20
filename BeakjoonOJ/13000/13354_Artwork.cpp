#include <stdio.h>

int par[1000001];

int find(int x){
	return par[x] == x ? x : (par[x] = find(par[x]));
}

int px, py;

bool link(int x, int y){
	par[px = find(x)] = (py = find(y));
	return px != py;
}

int x1[10000], y1[10000], x2[10000], y2[10000], ans[10000];
int cnt[1000][1000], dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

int main()
{
	int N, M, Q; scanf("%d %d %d", &N, &M, &Q);
	for(int i = 0; i < Q; i++){
		scanf("%d %d %d %d", &x1[i], &y1[i], &x2[i], &y2[i]);
		for(int j = x1[i] - 1; j < x2[i]; j++)
			for(int k = y1[i] - 1; k < y2[i]; k++)
				cnt[j][k]++;
	}

	for(int i = 0; i < N * M; i++) par[i] = i;

	int cur = N * M, black = 0;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++){
			if(cnt[i][j]){ black++; continue; }
			for(int k = 0; k < 4; k++){
				int nx = i + dx[k], ny = j + dy[k];
				if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
				if(!cnt[nx][ny]) cur -= link(i * M + j, nx * M + ny);
			}
		}

	for(int i = Q - 1; i >= 0; i--){
		// printf("%d %d\n", cur, black);
		ans[i] = cur - black;
		for(int j = x1[i] - 1; j < x2[i]; j++)
			for(int k = y1[i] - 1; k < y2[i]; k++){
				if(--cnt[j][k]) continue;
				black--;
				for(int w = 0; w < 4; w++){
					int nx = j + dx[w], ny = k + dy[w];
					if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
					if(!cnt[nx][ny]) cur -= link(j * M + k, nx * M + ny);
				}
			}
	}

	for(int i = 0; i < Q; i++)
		printf("%d\n", ans[i]);

	return 0;
}
