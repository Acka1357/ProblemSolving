#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

long long cnt[100001][2];
int par[100001];
vector<int> adj[100001];	// 부 -> 모

void dfs(int cur, int l = 0, int p = 0){
	cnt[cur][l]++;
	par[cur] = p;
	for(int i = 0; i < adj[cur].size(); i++){
		int &next = adj[cur][i];
		if(next == p) continue;
		dfs(next, 1 - l, cur);
		cnt[cur][0] += cnt[next][0];
		cnt[cur][1] += cnt[next][1];
	}
}

int main()
{
	int N, M, u, v, c; scanf("%d %d", &N, &M);
	for(int i = 1; i < N; i++){
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1);

	while(M--){
		scanf("%d %d %d", &u, &v, &c);
		if(par[u] == v) swap(u, v);
		long long ecnt = cnt[1][0] - cnt[v][0];
		long long ocnt = cnt[1][1] - cnt[v][1];
		if(c) printf("%lld\n", ocnt * cnt[v][0] + ecnt * cnt[v][1]);
		else printf("%lld\n", ecnt * cnt[v][0] + ocnt * cnt[v][1]);
	}
	return 0;
}
