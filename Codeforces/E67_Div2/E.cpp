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

int sub[200001], vi[200001], vcnt, p[200001];
ll res[200001], ans;

vector<int> adj[200001];

void dfs(int cur, int par){
	p[cur] = par;
	for(int nxt : adj[cur])
		if(nxt != par){
			dfs(nxt, cur);
			sub[cur] += sub[nxt];
			res[cur] += res[nxt] + sub[nxt];
		}
	sub[cur]++; res[cur]++;
	vi[vcnt++] = cur;
}

int main()
{
	int N; scanf("%d", &N);
	for(int i = 1, u, v; i < N; i++){
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1, 1);

	ll ans = res[1];
	for(int i = N - 2; i >= 0; i--){
		int cur = vi[i], par = p[cur];
		res[cur] = res[par] + N - 2 * sub[cur];
		ans = max(ans, res[cur]);
	}
	printf("%lld\n", ans);

	return 0;
}
