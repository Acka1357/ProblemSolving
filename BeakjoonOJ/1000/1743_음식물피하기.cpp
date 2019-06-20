#include <cstdio>
#include <algorithm>
using namespace std;

bool map[101][101];
int R, C, N, dr[] = {1, 0, -1, 0}, dc[] = {0, 1, 0, -1}, ans;

int dfs(int r, int c){
	int ret = 1;
	map[r][c] = false;
	for(int i = 0; i < 4; i++){
		int nr = r + dr[i], nc = c + dc[i];
		if(nr <= 0 || nc <= 0 || nr > R || nc > C) continue;
		if(map[nr][nc]) ret += dfs(nr, nc);
	}
	return ret;
}

int main()
{
	scanf("%d %d %d", &R, &C, &N);
	for(int i = 0, r, c; i < N; i++){
		scanf("%d %d", &r, &c);
		map[r][c] = true;
	}

	for(int i = 1; i <= R; i++)
		for(int j = 1; j <= C; j++)
			if(map[i][j]) ans = max(ans, dfs(i, j));
	printf("%d\n", ans);

	return 0;
}