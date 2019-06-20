#include <cstdio>
#include <cstring>

int N, d[5][10001];

int main()
{
	scanf("%d", &N);

	d[0][N] = 1;
	for(int i = 1; i <= 4; i++)
		for(int j = N; j >= 0; j--)
			for(int k = 0; k * k <= j; k++)
				d[i][j - k * k] += d[i - 1][j];
	printf("%d\n", d[4][0]);

	return 0;
}
