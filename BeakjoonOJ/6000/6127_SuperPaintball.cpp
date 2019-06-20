#include <cstdio>

bool map[100][100];
int dr[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dc[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int N, K, tot, ans;

int main()
{
	scanf("%d %d", &N, &K);
	for(int i = 0, r, c; i < K; i++){
		scanf("%d %d", &r, &c);
		tot += !map[r - 1][c - 1];
		map[r - 1][c - 1] = true;
	}

	for(int r = 0; r < N; r++)
		for(int c = 0; c < N; c++){
			int cnt = map[r][c];
			for(int i = 0; i < 8; i++)
				for(int nr = r + dr[i], nc = c + dc[i]; ; nr += dr[i], nc += dc[i]){
					if(nr < 0 || nr >= N || nc < 0 || nc >= N) break;
					cnt += map[nr][nc];
				}
			ans += cnt == tot;
		}
	printf("%d\n", ans);

	return 0;
}
