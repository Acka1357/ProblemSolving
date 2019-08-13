#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <utility>
#include <memory.h>
using namespace std;

#define MAXN	8

int dr[12] = {-3, -2, -1, 0, 1, 2, 3, 2, 1, 0, -1, -2};
int dc[12] = {0, 1, 2, 3, 2, 1, 0, -1, -2, -3, -2, -1};
long long N, M, ans[MAXN][MAXN];
bool map[MAXN][MAXN];

void dfs(int r, int c, long long cnt){
	if(c == M - 1){ r++; c = 0; }
	if(r == N){
		ans[N - 1][M - 1] = max(ans[N - 1][M - 1], cnt);
		return ;
	}

	if(!map[r][c]){
		map[r][c] = true;
		for(int i = 0; i < 12; i++){
			int nr = r + dr[i], nc = c + dc[i];
			if(nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
			if(!map[nr][nc]){
				map[nr][nc] = true;
				dfs(r, c + 1, cnt + 1);
				map[nr][nc] = false;
			}
		}
		map[r][c] = false;
	}
	dfs(r, c + 1, cnt);
}

int main()
{
	for(N = 1; N <= MAXN; N++)
		for(M = N; M <= MAXN; M++){
			if(N > M) swap(N, M);
			dfs(0, 0, 0);
			printf("%lld X %lld: %lld\n", N, M, ans[N - 1][M - 1]);
		}

	for(int i = 1; i <= MAXN; i++){
		for(int j = 1; j <= MAXN; j++)
			printf("%3d", ans[i][j]);
	}
	return 0;
}
