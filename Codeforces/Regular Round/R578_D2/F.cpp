#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

struct Edge{ int to, m; };

const int mod = 2520;

int N, k[1005], ans[1005][mod], t[1005][mod], ts, tcur, chk[1005], his[1005 * mod + 1];
Edge nxt[1005][mod];

int dfs(int cur, int m){
	Edge &e = nxt[cur][m];
	t[cur][m] = ++tcur;
	his[tcur] = cur;
	if(t[e.to][e.m] >= ts){
		int pt = t[e.to][e.m], cnt = 0;
		for(int i = pt; i <= tcur; i++)
			if(chk[his[i]] != tcur){
				cnt++;
				chk[his[i]] = tcur;
			}
		return ans[cur][m] = cnt;
	}
	else if(t[e.to][e.m])
		return ans[cur][m] = ans[e.to][e.m];

	return ans[cur][m] = dfs(e.to, e.m);
}

int main()
{
	scanf("%d", &N);
	for(int i = 1; i <= N; i++){
		scanf("%d", &k[i]);
		k[i] = ((k[i] % mod) + mod) % mod;
	}

	for(int i = 1; i <= N; i++){
		int e; scanf("%d", &e);
		vector<int> to;
		for(int j = 0, x; j < e; j++){
			scanf("%d", &x);
			to.push_back(x);
		}
		for(int m = 0; m < mod; m++){
			int tom = (m + k[i]) % mod;
			nxt[i][m] = {to[tom % e], tom};
		}
	}

	for(int i = 1; i <= N; i++)
		for(int m = 0; m < mod; m++)
			if(!t[i][m]){
				ts = tcur + 1;
				dfs(i, m);
			}

	ll Q, x, y; for(scanf("%lld", &Q); Q--;){
		scanf("%lld %lld", &x, &y);
		printf("%d\n", ans[x][((y % mod) + mod) % mod]);
	}	

	return 0;
}