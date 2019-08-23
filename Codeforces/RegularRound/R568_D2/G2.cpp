#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <utility>
#include <functional>
#include <cstdlib>
#include <cmath>
#include <string>
#include <set>
#include <map>
using namespace std;

typedef long long ll;

const ll mod = 1000000007;

int t[51], g[51], gcum[3], f[51];;
ll d[2501][52][52][52], cnt[51][51][51][3];

int main()
{
	int N, T; scanf("%d %d", &N, &T);
	for(int i = 0; i < N; i++){
		scanf("%d %d", &t[i], &g[i]);
		gcum[g[i] - 1]++;
	}
	
	f[1] = 1;
	for(int i = 2; i <= N; i++)
		f[i] = (f[i - 1] * i) % mod;

	d[0][0][0][0] = 1;
	for(int i = 0; i < N; i++)
		for(int st = 0; st <= T - t[i]; st++)
			for(int g1 = 0; g1 <= min(gcum[0], i); g1++)
				for(int g2 = 0; g2 <= min(gcum[1], i); g2++)
					for(int g3 = 0; g3 <= min(gcum[2], i); g3++){
						if(g1 + g2 + g3 >= N) break;
						d[st + t[i]][g1 + (g[i] == 1)][g2 + (g[i] == 2)][g3 + (g[i] == 3)] 
							= (d[st + t[i]][g1 + (g[i] == 1)][g2 + (g[i] == 2)][g3 + (g[i] == 3)] + 
							   d[st][g1][g2][g3]) % mod;
					}

	ll ans = 0;
	if(gcum[0]) cnt[1][0][0][0] = 1;
	if(gcum[1]) cnt[0][1][0][1] = 1;
	if(gcum[2]) cnt[0][0][1][2] = 1;
	for(int g1 = 0; g1 <= gcum[0]; g1++)
		for(int g2 = 0; g2 <= gcum[1]; g2++)
			for(int g3 = 0; g3 <= gcum[2]; g3++){
				if(g1 + g2 + g3 > N) break;
				if(g1) cnt[g1][g2][g3][0] += (gcum[0] - g1 - 1) * (cnt[g1 - 1][g2][g3][1] + cnt[g1 - 1][g2][g3][2]);
				if(g2) cnt[g1][g2][g3][1] += (gcum[1] - g2 - 1) * (cnt[g1][g2 - 1][g3][0] + cnt[g1][g2 - 1][g3][2]);
				if(g3) cnt[g1][g2][g3][2] += (gcum[2] - g3 - 1) * (cnt[g1][g2][g3 - 1][0] + cnt[g1][g2][g3 - 1][1]);
				cnt[g1][g2][g3][0] %= mod;
				cnt[g1][g2][g3][1] %= mod;
				cnt[g1][g2][g3][2] %= mod;
			}

	for(int g1 = 0; g1 <= N; g1++)
		for(int g2 = 0; g2 <= N; g2++)
			for(int g3 = 0; g3 <= N; g3++){
				if(g1 + g2 + g3 > N) break;
				ll cs = (cnt[g1][g2][g3][0] + cnt[g1][g2][g3][1] + cnt[g1][g2][g3][2]) % mod;
				// if(g1) cs = (cs * f[g1]) % mod;
				// if(g2) cs = (cs * f[g2]) % mod;
				// if(g3) cs = (cs * f[g3]) % mod;
				// printf("%d / %d / %d : %lld * %lld\n", g1, g2, g3, d[T][g1][g2][g3], cs);
				ans = (ans + d[T][g1][g2][g3] * cs) % mod;
			}
	printf("%lld\n", ans % mod);

	return 0;
}
