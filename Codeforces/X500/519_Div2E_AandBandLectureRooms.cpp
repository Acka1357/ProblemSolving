#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

const int D = 16;

vector<int> adj[100005];
int dth[100005], ts, in[100005], out[100005], anc[D + 1][100005], sub[100005];

void dfs(int cur, int par){
	dth[cur] = dth[par] + 1;
	anc[0][cur] = par;
	in[cur] = ++ts;
	for(int nxt : adj[cur])
		if(nxt != par){
			dfs(nxt, cur);
			sub[cur] += sub[nxt];
		}
	sub[cur]++;
	out[cur] = ++ts;
}

int get_lca(int u, int v){
	if(in[u] <= in[v] && out[v] <= out[u]) return u;
	for(int i = D; i >= 0; i--)
		if(anc[i][u] && (in[v] < in[anc[i][u]] || out[anc[i][u]] < out[v]))
			u = anc[i][u];
	return anc[0][u];
}

int get_kth_anc(int v, int k){
	for(int i = 0, b = 1; k; i++, b <<= 1)
		if(k & b) v = anc[i][v], k ^= b;
	return v;
}

int main()
{
	int N; scanf("%d", &N);
	for(int i = 1, u, v; i < N; i++){
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1, 0);
	for(int i = 1; i <= D; i++)
		for(int j = 1; j <= N; j++)
			anc[i][j] = anc[i - 1][anc[i - 1][j]];

	int Q; for(scanf("%d", &Q); Q--;){
		int u, v; scanf("%d %d", &u, &v);
		int lca = get_lca(u, v), ans = -1;
		if(u == v) ans = N;
		else if(dth[u] == dth[v])
			ans = N - sub[get_kth_anc(u, dth[u] - dth[lca] - 1)] - sub[get_kth_anc(v, dth[v] - dth[lca] - 1)];
		else if((dth[u] + dth[v]) & 1) ans = 0;
		else{
			int son = (dth[u] < dth[v]) ? v : u;
			int par = (dth[u] < dth[v]) ? u : v;			
			int len = dth[u] + dth[v] - 2 * dth[lca];
			int mid = get_kth_anc(son, len / 2);
			ans = sub[mid] - sub[get_kth_anc(son, len / 2 - 1)];
		}
		printf("%d\n", ans);
	}

	return 0;
}