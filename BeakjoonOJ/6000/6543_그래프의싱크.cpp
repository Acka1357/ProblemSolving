// solution:
// 그래프에서 어떤 노드 u가 싱크이기 위해서는 u->v 간선이 존재하는 모든 v에 대해
// v에서 u로 돌아올 수 있어야 한다.
// SCC로 DAG를 형성한 후 outdegree가 0인 컴포넌트의 모든 정점이 답이 된다.

// 시간복잡도: O(E)
// 분류: SCC
// 난이도: 2000 (SCC가 귀찮기 때문이지 어려워서는 아님)

#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int ts[5001], low[5001], t, vst[5001], vtop, ci[5001];
vector<int> adj[5001];
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
			if(ci[nxt] != cur) ts[cur] = 2;
			if(ts[ci[nxt]] <= 0) dfs2(ci[nxt]);
		}
}

int main()
{
	int V, E;
	while(scanf("%d", &V) == 1){
		if(!V) return 0;
		scanf("%d", &E);

		scc.clear();
		t = vtop = 0;
		memset(ts, 0, sizeof(ts));
		memset(low, 0, sizeof(low));
		for(int i = 1; i <= V; i++)
			adj[i].clear();

		for(int i = 0, u, v; i < E; i++){
			scanf("%d %d", &u, &v);
			adj[u].push_back(v);
		}

		for(int i = 1; i <= V; i++)
			if(!ts[i]) dfs(i);

		int C = scc.size();
		for(int i = 0; i < C; i++)
			if(ts[i] <= 0) dfs2(i);

		vector<int> ans;
		for(int i = 0; i < C; i++){
			if(ts[i] == 2) continue;
			for(int &v : scc[i])
				ans.push_back(v);
		}

		sort(ans.begin(), ans.end());

		for(int i = 0; i < ans.size(); i++)
			printf("%d%c", ans[i], " \n"[i == ans.size() - 1]);
	}

	return 0;
}
