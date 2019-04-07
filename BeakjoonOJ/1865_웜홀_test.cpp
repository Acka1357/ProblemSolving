#include <stdio.h>
#include <memory.h>
#include <algorithm>
using namespace std;

int d[501][501];

int main()
{
	int T; for(scanf("%d", &T); T--;){
		int N, M, W; scanf("%d %d %d", &N, &M, &W);
		memset(d, 0x3f, sizeof(d));
		for(int i = 1; i <= N; i++)
			d[i][i] = 0;
		for(int i = 0, u, v, c; i < M; i++){
			scanf("%d %d %d", &u, &v, &c);
			d[u][v] = d[v][u] = min(d[u][v], c);
		}
		for(int i = 0, u, v, c; i < W; i++){
			scanf("%d %d %d", &u, &v, &c);
			d[u][v] = min(d[u][v], -c);
		}

		for(int k = 1; k <= N; k++)
			for(int i = 1; i <= N; i++)
				for(int j = 1; j <= N; j++)
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

		bool ans = false;
		for(int i = 1; i <= N; i++)
			if(d[i][i] < 0) ans = true;
		printf("%s\n", ans ? "YES" : "NO");
	}
	return 0;
}
