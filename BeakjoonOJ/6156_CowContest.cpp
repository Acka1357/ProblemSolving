// 분류: Floyd-Warshall
// 난이도: 1250

#include <cstdio>

bool win[101][101];

int main()
{
	int N, M; scanf("%d %d", &N, &M);
	for(int i = 0, u, v; i < M; i++){
		scanf("%d %d", &u, &v);
		win[u - 1][v - 1] = true;
	}

	for(int k = 0; k < N; k++)
		for(int i = 0; i < N; i++)
			for(int j = 0; j < N; j++)
				win[i][j] |= win[i][k] & win[k][j];

	int ans = N;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			if(i != j && !(win[i][j] | win[j][i])){
				ans--; break;
			}
	printf("%d\n", ans);

	return 0;
}