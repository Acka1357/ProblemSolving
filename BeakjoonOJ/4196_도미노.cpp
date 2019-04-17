// 분류: SCC

#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

bool chk[100001];
int ts[100001], low[100001], t, vst[100001], vtop, ci[100001], ans;
vector<int> adj[100001];
vector<vector<int>> scc;

int dfs(int cur){
	ts[cur] = low[cur] = ++t;
	vst[vtop++] = cur;
	for(int &nxt : adj[cur]){
		if(!ts[nxt]) low[cur] = min(low[cur], dfs(nxt));
		else if(ts[nxt] > 0) low[cur] = min(low[cur], ts[nxt]);
	}
	if(ts[cur] == low[cur]){
		vector<int> sc;
		do{
			sc.push_back(vst[--vtop]);
			ci[vst[vtop]] = scc.size();
			ts[vst[vtop]] = -1;
		} while(vst[vtop] != cur);
		scc.push_back(sc);
	}
	return low[cur];
}

void dfs2(int cur){
	ts[cur] = 1;
	for(int &v : scc[cur])
		for(int &nxt : adj[v]){
			int nc = ci[nxt];
			if(nc != cur && !chk[nc]) ans--, chk[nc] = true;
			if(ts[nc] <= 0) dfs2(nc);
		}
}

int main()
{
	int tc; for(scanf("%d", &tc); tc--;){
		scc.clear();
		t = vtop = 0;
		memset(chk, false, sizeof(chk));
		memset(ts, 0, sizeof(ts));
		memset(low, 0, sizeof(low));

		int V, E; scanf("%d %d", &V, &E);
		for(int i = 1; i <= V; i++)
			adj[i].clear();
		for(int i = 0, u, v; i < E; i++){
			scanf("%d %d", &u, &v);
			adj[u].push_back(v);
		}

		for(int i = 1; i <= V; i++)
			if(!ts[i]) dfs(i);

		int C = ans = scc.size();
		for(int i = 0; i < C; i++)
			if(ts[i] <= 0) dfs2(i);
		printf("%d\n", ans);
	}

	return 0;
}