#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

int cnt[1000006];

int main()
{
	long long N, M; scanf("%lld %lld", &N, &M);
	for(int i = 0, u, v; i < M; i++){
		scanf("%d %d", &u, &v);
		cnt[u]++; cnt[v]++;
	}

	ll ans = N * (N - 1) * (N - 2) / 3;
	for(int i = 1; i <= N; i++)
		ans -= cnt[i] * (N - cnt[i] - 1);
	printf("%lld\n", ans / 2);

	return 0;
}