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

int t[16], g[16], b[16];
ll d[16][1 << 16];

int main()
{
	int N, T; scanf("%d %d", &N, &T);
	for(int i = 0; i < N; i++){
		scanf("%d %d", &t[i], &g[i]);
		d[i][1 << i] = 1;
		b[i] = (1 << i);
	}

	int fill = (1 << N) - 1;
	for(int i = 1; i < fill; i++)
		for(int cur = 0; cur < N; cur++){
			if((i & b[cur]) != b[cur]) continue;
			for(int nxt = 0; nxt < N; nxt++){
				if((i & b[nxt]) != 0) continue;
				if(g[cur] == g[nxt]) continue;
				d[nxt][i | b[nxt]] = (d[nxt][i | b[nxt]] + d[cur][i]) % mod;
			}
		}

	ll ans = 0;
	for(int i = 0; i < N; i++)
		for(int st = 1; st <= fill; st++){
			int tot = 0;
			for(int j = 0, cs = st; j < N; j++, cs >>= 1)
				if(cs & 1) tot += t[j];
			if(tot == T) ans += d[i][st];
		}
	printf("%lld\n", ans % mod);

	return 0;
}
