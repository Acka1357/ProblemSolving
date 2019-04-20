// solution:
// SCC 후의 DAG에서 indegree가 0인 컴포넌트가 유일할 경우 해당 컴포넌트의 모든 원소가 답.
// 유일하지 않다면 불가능.

// 시간복잡도: O(E)
// 난이도: 2000 (SCC를 아냐 모르냐 문제)
// 분류: SCC

#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

bool ind[100001];
int idx[100001], low[100001], t, ci[100001], vs[100001], vtop;
vector<vector<int>> adj, scc;

int dfs(int cur){
	idx[cur] = low[cur] = ++t;
	vs[vtop++] = cur;
	for(int nxt : adj[cur]){
		if(!idx[nxt]) low[cur] = min(low[cur], dfs(nxt));
		else if(idx[nxt] > 0) low[cur] = min(low[cur], idx[nxt]);
	}
	if(idx[cur] == low[cur]){
		vector<int> sc;
		do{
			sc.push_back(vs[--vtop]);
			ci[vs[vtop]] = scc.size();
			idx[vs[vtop]] = -1;
		} while(vs[vtop] != cur);
		scc.push_back(sc);
	}
	return low[cur];
}

void dfs2(int cur){
	idx[cur] = 1;
	for(int &v : scc[cur])
		for(int &nxt : adj[v]){
			if(ci[nxt] != cur) ind[ci[nxt]] = true;
			if(idx[ci[nxt]] != 1) dfs2(ci[nxt]);
		}
}

int main()
{
	int tc; for(scanf("%d", &tc); tc--;){
		memset(ind, false, sizeof(ind));
		memset(idx, 0, sizeof(idx));
		scc.clear();
		t = vtop =0;

		int V, E; scanf("%d %d", &V, &E);
		adj = vector<vector<int>>(V + 1, vector<int>());
		for(int i = 0, u, v; i < E; i++){
			scanf("%d %d", &u, &v);
			adj[u + 1].push_back(v + 1);
		}
		for(int i = 1; i <= V; i++)
			if(!idx[i]) dfs(i);

		V = scc.size();
		for(int i = 0; i < V; i++)
			if(idx[i] <= 0) dfs2(i);

		int ans = -1, cnt = 0;
		for(int i = 0; i < V; i++)
			if(!ind[i]) ans = i, cnt++;

		if(cnt != 1) printf("Confused\n");
		else{
			sort(scc[ans].begin(), scc[ans].end());
			for(int v : scc[ans])
				printf("%d\n", v - 1);
		}
		if(tc) printf("\n");
	}
	return 0;
}