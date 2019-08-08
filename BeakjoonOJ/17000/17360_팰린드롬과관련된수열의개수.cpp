#include <cstdio>

typedef long long ll;

const ll mod = 1000000007;

int main()
{
	ll N, M, K; scanf("%lld %lld %lld", &N, &M, &K);

	int cnt = (K & 1) ? 2 : 1;
	if(N < K || K == 1) cnt = N;
	else if(N == K) cnt = (N + 1) / 2;

	ll ans = 1;
	for(int i = 0; i < cnt; i++)
		ans = (ans * M) % mod;
	printf("%lld\n", ans);

	return 0;
}