#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int p[100001];
ll subc[100001][2];
vector<int> adj[100001];

void dfs(int cur, int d){
	for(int ch : adj[cur]){
		if(p[ch]) continue;
		p[ch] = cur;
		dfs(ch, 1 - d);
		subc[cur][0] += subc[ch][0];
		subc[cur][1] += subc[ch][1];
	}
	subc[cur][d]++;
}

int main()
{
	int N, M; scanf("%d %d", &N, &M);
	for(int i = 1, u, v; i < N; i++){
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	p[1] = -1;
	dfs(1, 0);

	for(int i = 0, u, v, c; i < M; i++){
		scanf("%d %d %d", &u, &v, &c);
		if(p[u] == v) swap(u, v);
		ll p0 = subc[1][0] - subc[v][0], p1 = subc[1][1] - subc[v][1];
		ll c0 = subc[v][c], c1 = subc[v][1 - c];
		printf("%lld\n", p0 * c0 + p1 * c1);
	}

	return 0;
}
