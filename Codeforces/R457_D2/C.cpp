#include <stdio.h>

#define P	100003

int main()
{
	int N, M; scanf("%d %d", &N, &M);

	printf("%d %d\n", P, P);
	for(int i = 1; i < N - 1; i++)
		printf("%d %d %d\n", i, i + 1, 1);
	printf("%d %d %d\n", N - 1, N, P - N + 2);

	M -= N - 1;
	for(int i = 1; i < N && M; i++)
		for(int j = i + 2; j <= N && M; j++){
			printf("%d %d 1000000000\n", i, j);
			M--;
		}

	return 0;
}