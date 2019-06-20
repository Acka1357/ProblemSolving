#include <stdio.h>

int cum[100001][3];

int main()
{
	int N, Q, a, b; scanf("%d %d", &N, &Q);
	for(int i = 1, x; i <= N; i++){
		scanf("%d", &x);
		for(int j = 0; j < 3; j++)
			cum[i][j] = cum[i - 1][j] + (j == x - 1);
	}

	while(Q--){
		scanf("%d %d", &a, &b);
		for(int i = 0; i < 3; i++)
			printf("%d ", cum[b][i] - cum[a - 1][i]);
		printf("\n");
	}

	return 0;
}