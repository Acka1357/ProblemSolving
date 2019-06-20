#include <stdio.h>
#include <memory.h>
#include <algorithm>
using namespace std;

int d[501][500], x[501], y[501];
int absx(int x){ return x < 0 ? -x : x; }
int dist(int i1, int i2){ return absx(x[i1] - x[i2]) + absx(y[i1] - y[i2]); }

int main()
{
	int N, K; scanf("%d %d", &N, &K);
	for(int i = 1; i <= N; i++)
		scanf("%d %d", &x[i], &y[i]);

	memset(d, 0x3f, sizeof(d));
	d[1][0] = 0;
	for(int i = 2; i <= N; i++)
		for(int k = min(K, i - 1); k >= 0; k--)
			for(int j = k + 1; j > 0; j--)
				d[i][k] = min(d[i][k], d[i - j][k - j + 1] + dist(i - j, i));

	int ans = d[N][0];
	for(int i = 1; i <= K; i++)
		ans = min(ans, d[N][i]);

	printf("%d\n", ans);
	return 0;
}