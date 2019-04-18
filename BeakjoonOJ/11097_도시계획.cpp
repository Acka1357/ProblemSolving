// solution:
// SCC가 있다면 사이클의 크기만큼의 엣지로 SCC 안의 연결성은 모두 나타낼 수 있다.
// 이후 DAG가 된 그래프에서 꼭 필요한 간선만을 뽑으려면 플로이드-워셜 알고리즘으로 체크가 가능하다.
// 하지만 귀찮으니 컴포넌트 u에서 v로 가능 간선이 꼭 필요하다는 것은
// u의 다른 간선을 통해 갈 수 있는 정점 u'에서 v로 갈 수 있는 경로가 없어야 한다는 것이고
// 현재 그래프는 트랜지티브 클로져가 주어졌으니 모든 경로를 보지 않고
// u -> u' -> v 의 경로 2짜리만 보는 것으로 충분하다.
// 이런 u'이 하나라도 존재한다면 u -> v 다이렉트 엣지는 필요가 없다.

// 시간복잡도: O(E + V^3)
// 난이도: 2000-2250 (SCC가 귀찮기때문에)
// 분류: SCC, Floyd-Warshall

#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int V, idx[301], low[301], t, ci[301], vs[301], vtop, rep[301], ans[90000][2], ansi;
vector<int> adj[301];
vector<vector<int>> scc, sdj;

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
		rep[scc.size()] = cur;
		scc.push_back(sc);
	}
	return low[cur];
}

void build(int cur){
	vector<int> nxt;
	for(int v : scc[cur])
		for(int nv : adj[v])
			if(cur != ci[nv]) nxt.push_back(ci[nv]);
	sort(nxt.begin(), nxt.end());
	nxt.erase(unique(nxt.begin(), nxt.end()), nxt.end());
	sdj.push_back(nxt);
}

void find(int cur){
	vector<bool> need(V, false);
	for(int nxt : sdj[cur])
		need[nxt] = true;
	for(int nxt : sdj[cur])
		for(int nnxt : sdj[nxt])
			need[nnxt] = false;
	for(int i = 0; i < V; i++)
		if(need[i]){
			ans[ansi][0] = rep[cur];
			ans[ansi++][1] = rep[i];
		}
	if(scc[cur].size() > 1){
		for(int i = 0; i < scc[cur].size(); i++){
			ans[ansi][0] = scc[cur][i];
			ans[ansi++][1] = scc[cur][(i + 1) % scc[cur].size()];
		}
	}
}

int main()
{
	int tc; for(scanf("%d", &tc); tc--;){
		memset(idx, 0, sizeof(idx));
		scc.clear(); sdj.clear();
		t = vtop = ansi = 0;

		scanf("%d", &V);
		for(int i = 1, x; i <= V; i++){
			adj[i].clear();
			for(int j = 1; j <= V; j++){
				scanf("%1d", &x);
				if(x && i != j) adj[i].push_back(j);
			}
		}

		for(int i = 1; i <= V; i++)
			if(!idx[i]) dfs(i);

		V = scc.size();
		for(int i = 0; i < V; i++)
			build(i);
		for(int i = 0; i < V; i++)
			find(i);

		printf("%d\n", ansi);
		for(int i = 0; i < ansi; i++)
			printf("%d %d\n", ans[i][0], ans[i][1]);
		if(tc) printf("\n");
	}
	return 0;
}