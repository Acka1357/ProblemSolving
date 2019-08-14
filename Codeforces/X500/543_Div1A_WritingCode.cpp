#include <cstdio>

typedef long long ll;

ll a[502], d[502][502];

int main()
{
	int N, M, B, mod; scanf("%d %d %d %d", &N, &M, &B, &mod);
	for(int i = 1; i <= N; i++)
		scanf("%lld", &a[i]);

	d[0][0] = 1;
	for(int i = 1; i <= N; i++)
		for(int j = 0; j <= M; j++)
			for(int k = 0; k <= B; k++){
				if(j && k >= a[i]) d[j][k] += d[j - 1][k - a[i]];
				d[j][k] %= mod;
			}

	ll ans = 0;
	for(int i = 0; i <= B; i++)
		ans += d[M][i];
	printf("%lld\n", ans % mod);

	return 0;
}