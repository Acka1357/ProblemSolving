#include <stdio.h>

int d[16][16];

int main()
{
	int N, M, K; scanf("%d %d %d", &N, &M, &K);

	int r = K ? (K - 1) / M : 0, c = K ? (K - 1) % M : 0;
	d[0][0] = 1;
	for(int i = 0; i <= r; i++)
		for(int j = 0; j <= c; j++){
			if(i) d[i][j] += d[i - 1][j];
			if(j) d[i][j] += d[i][j - 1];
		}
	for(int i = r; i < N; i++)
		for(int j = c; j < M; j++){
			if(i != r) d[i][j] += d[i - 1][j];
			if(j != c) d[i][j] += d[i][j - 1];
		}

	printf("%d\n", d[N - 1][M - 1]);
	return 0;
}