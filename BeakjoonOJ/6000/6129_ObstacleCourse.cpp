#include <cstdio>
#include <queue>
using namespace std;

struct Crd{ int r, c; };

int dr[4] = {0, 1, 0, -1}, dc[4] = {1, 0, -1, 0};
int N, sr, sc, mint[101][101];
char map[101][101];

bool valid(int r, int c){
	return 0 <= r && r < N && 0 <= c && c < N;
}

int main()
{
	queue<Crd> q;
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%s", map[i]);
		for(int j = 0; j < N; j++)
			if(map[i][j] == 'A') sr = i, sc = j;
	}

	q.push({sr, sc});
	mint[sr][sc] = 1;
	for(int d = 0; d < 4; d++)
		for(int nr = sr + dr[d], nc = sc + dc[d]; valid(nr, nc); nr += dr[d], nc += dc[d]){
			if(map[nr][nc] == 'x') break;
			if(mint[nr][nc]) continue;
			q.push({nr, nc});
			mint[nr][nc] = 1;
		}

	while(!q.empty()){
		int r = q.front().r, c = q.front().c; q.pop();
		if(map[r][c] == 'B') return !printf("%d\n", mint[r][c] - 1);
		for(int d = 0; d < 4; d++)
			for(int nr = r + dr[d], nc = c + dc[d]; valid(nr, nc); nr += dr[d], nc += dc[d]){
				if(map[nr][nc] == 'x') break;
				if(mint[nr][nc]) continue;
				q.push({nr, nc});
				mint[nr][nc] = mint[r][c] + 1;
			}
	}
	printf("-1\n");

	return 0;
}
