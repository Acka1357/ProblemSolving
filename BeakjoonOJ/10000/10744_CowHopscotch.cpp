#include <stdoi.h>

#define MOD		1000000007

long long a[751][751], d[751][751];

int main()
{
	int R, C, K; scanf("%d %d %d", &R, &C, &K);
	for(int i = 1; i <= R; i++)
		for(int j = 1; j <= C; j++)
			scanf("%d", &a[i][j]);

	d[1][1] = 1;
	for(int i = 1; i <= R; i++)
		for(int j = 1; j <= C; j++){
			
		}

	printf("%lld\n", d[R][C]);
	return 0;
}