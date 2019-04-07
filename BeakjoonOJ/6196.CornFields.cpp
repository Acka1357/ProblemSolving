#include <cstdio>

typedef long long ll;
const int MOD = 100000000;

int map[13][12];
ll d[12 * 13][1 << 11];

int main()
{
	int R, C; scanf("%d %d", &R, &C);
	for(int i = 0; i < R; i++)
		for(int j = 0; j < C; j++)
			scanf("%d", &map[i][j]);
	for(int j = 0; j < C; j++) map[R][j] = 1;

	d[0][0] = 1;
	int fill = (1 << C), newb = (1 << (C - 1));
	for(int i = 0; i < R * C; i++)
		for(int st = 0; st < fill; st++){
			d[i][st] %= MOD;
			d[i + 1][st >> 1] += d[i][st];
			if(!(st & 1) && map[i / C][i % C])
				d[i + 1][(st >> 1) | newb | (i % C != C - 1)] += d[i][st];
		}

	ll ans = 0;
	for(int i = 0; i < fill; i++)
		ans += d[R * C][i];
	printf("%lld\n", ans % MOD);

	return 0;
}
