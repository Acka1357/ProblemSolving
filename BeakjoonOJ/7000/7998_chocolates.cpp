#include <stdio.h>
#include <memory.h>
#include <algorithm>
using namespace std;

long long x[1001], y[1001], d[1001][1001];

int main()
{
	int N, M; scanf("%d %d", &M, &N);

	for(int i = 1; i < M; i++)
		scanf("%lld", &x[i]);

	for(int i = 1; i < N; i++)
		scanf("%lld", &y[i]);

	sort(x + 1, x + M);
	reverse(x + 1, x + M);
	sort(y + 1, y + N);
	reverse(y + 1, y + N);

	memset(d, 0x3f, sizeof(d));
	d[0][0] = 0;
	for(int i = 0; i < M; i++)
		for(int j = 0; j < N; j++){
			if(i) d[i][j] = min(d[i][j], d[i - 1][j] + x[i] * (j + 1));
			if(j) d[i][j] = min(d[i][j], d[i][j - 1] + y[j] * (i + 1));
		}

	printf("%lld\n", d[M - 1][N - 1]);

	return 0;
}
