// 분류: Floyd-Warshall

#include <cstdio>

bool order[401][401];

int main()
{
	int N, M; scanf("%d %d", &N, &M);
	for(int i = 0, u, v; i < M; i++){
		scanf("%d %d", &u, &v);
		order[u][v] = true;
	}

	for(int k = 1; k <= N; k++)
		for(int i = 1; i <= N; i++)
			for(int j = 1; j <= N; j++)
				order[i][j] |= order[i][k] & order[k][j];

	int Q, u, v; for(scanf("%d", &Q); Q--;){
		scanf("%d %d", &u, &v);
		printf("%d\n", order[u][v] ? -1 : (order[v][u] ? 1 : 0));
	}

	return 0;
}