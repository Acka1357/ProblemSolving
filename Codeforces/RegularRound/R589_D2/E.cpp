#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

const ll mod = 1000000007;

ll dr[300], comb[300][300], d[300][300], c[300][300];

int main()
{
	ll N, K; scanf("%lld %lld", &N, &K);
	dr[N] = 1;
	for(int i = N - 1; i > 0; i--)
		dr[i] = (dr[i + 1] * (K - 1)) % mod;

	for(int i = comb[0][0] = 1; i <= N; i++)
		for(int j = comb[i][0] = 1; j <= N; j++)
			comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % mod;

	for(int pcnt = 0; pcnt <= N; pcnt++)
		for(int ncnt = pcnt; ncnt <= N; ncnt++)
			for(int cur = ncnt - pcnt; cur <= ncnt; cur++){
				int has = pcnt;
				int nhas = N - pcnt;
				int out = ncnt - pcnt;
				int in = cur - out;
				ll cc = (comb[has][in] * comb[nhas][out]) % mod;
				c[pcnt][ncnt] += dr[cur] * cc;
				c[pcnt][ncnt] %= mod;
			}

	d[0][0] = 1;
	for(int i = 1; i <= N; i++)
		for(int pcnt = 0; pcnt <= N; pcnt++)
			for(int ncnt = pcnt; ncnt <= N; ncnt++){
				d[i][ncnt] += d[i - 1][pcnt] * c[pcnt][ncnt];
				d[i][ncnt] %= mod;
			}

	printf("%lld\n", d[N][N]);

	return 0;
}