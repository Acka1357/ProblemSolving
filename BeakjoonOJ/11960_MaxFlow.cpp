#include <stdio.h>
#include <vector>
using namespace std;

vector<int> adj[50001];
int anc[50001][16], in[50001], out[50001], t;
int add[50001], ans;

void set_anc(int cur, int p){
	for(int i = 1; i < 16; i++){
		if(!anc[cur][i - 1]) break;
		anc[cur][i] = anc[anc[cur][i - 1]][i - 1];
	}

	in[cur] = ++t;
	for(int i = 0; i < adj[cur].size(); i++)
		if(adj[cur][i] != p){
			anc[adj[cur][i]][0] = cur;
			set_anc(adj[cur][i], cur);
		}
	out[cur] = ++t;
}

int get_lca(int u, int v){
	if(in[u] <= in[v] && out[v] <= out[u]) return u;
	for(int i = 15; i >= 0; i--){
		if(!anc[u][i]) continue;
		if(in[v] < in[anc[u][i]] || out[anc[u][i]] < out[v])
			u = anc[u][i];
	}
	return anc[u][0];
}

void calc(int cur, int p){
	for(int i = 0; i < adj[cur].size(); i++)
		if(adj[cur][i] != p){
			calc(adj[cur][i], cur);
			add[cur] += add[adj[cur][i]];
		}
	if(ans < add[cur]) ans = add[cur];
}

int main()
{
	int N, K, x, y; scanf("%d %d", &N, &K);
	for(int i = 1, u, v; i < N; i++){
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	set_anc(1, 0);

	while(K--){
		scanf("%d %d", &x, &y);
		int lca = get_lca(x, y);
		add[x]++; add[y]++;
		add[lca]--; add[anc[lca][0]]--;
	}

	calc(1, 0);
	printf("%d\n", ans);
	return 0;
}