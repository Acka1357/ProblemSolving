#include <cstdio>

long long d[10001];

int main()
{
	int V, N; scanf("%d %d", &V, &N);
	d[0] = 1;
	for(int i = 0, c; i < V; i++){
		scanf("%d", &c);
		for(int j = c; j <= N; j++)
			d[j] += d[j - c];
	}
	printf("%lld\n", d[N]);

	return 0;
}