#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long ll;

ll d[18][1 << 18];
int c[18], w[18][18], bit[18];

int main()
{
	int N, M, K; scanf("%d %d %d", &N, &M, &K);
	for(int i = 0; i < N; i++)
		scanf("%d", &c[i]), bit[i] = (1 << i);
	for(int i = 0, a, b, x; i < K; i++){
		scanf("%d %d %d", &a, &b, &x);
		a--; b--;
		w[a][b] = max(w[a][b], x);
	}

	int last = (1 << N);
	for(int st = 0; st < last; st++)
		for(int cur = 0; cur < N; cur++){
			if(st && !(st & bit[cur])) continue;
			for(int nxt = 0; nxt < N; nxt++){
				if(st & bit[nxt]) continue;
				d[nxt][st | bit[nxt]] = max(d[nxt][st | bit[nxt]], 
											d[cur][st] + (st ? w[cur][nxt] : 0) + c[nxt]);
			}
		}

	ll ans = 0;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < last; j++)
			if(__builtin_popcount(j) == M)
				ans = max(ans, d[i][j]);
	printf("%lld\n", ans);

	return 0;
}