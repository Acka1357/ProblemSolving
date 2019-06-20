#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[50001];
int in[50001], out[50001], anc[50001][16], t;

void dfs(int cur, int p){
	anc[cur][0]= p;
	for(int i = 1; i <= 15; i++){
		if(!anc[cur][i - 1]) break;
		anc[cur][i] = anc[anc[cur][i - 1]][i - 1];
	}

	in[cur] = ++t;
	for(int i = 0; i < adj[cur].size(); i++)
		if(adj[cur][i] != p) dfs(adj[cur][i], cur);
	out[cur] = ++t;
}

int get_lca(int u, int v){
	if(in[u] <= in[v] && out[v] <= out[u]) return u;
	for(int i = 15; i >= 0; i--){
		if(!anc[u][i]) continue;
		if(in[anc[u][i]] > in[v] || out[v] > out[anc[u][i]])
			u = anc[u][i];
	}
	return anc[u][0];
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int N, M, u, v; cin >> N;
	for(int i = 1, u, v; i < N; i++){
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1, 0);
	for(cin >> M; M--;){
		cin >> u >> v;
		cout << get_lca(u, v) << "\n";
	}
	return 0;
}