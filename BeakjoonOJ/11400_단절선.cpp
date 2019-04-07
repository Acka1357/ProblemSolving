#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge{
	int u, v;
	Edge(int u, int v):u(min(u, v)), v(max(u, v)){}
	bool operator <(const Edge &o)const{
		return u == o.u ? v < o.v : u < o.u;
	}
};

bool cutv[100001];
int ans_cnt, t, ts[100001], low[100001];
vector<int> adj[100001];
vector<Edge> ans;

void dfs(int cur, int past){
	ts[cur] = low[cur] = ++t;
	for(int i = 0; i < adj[cur].size(); i++){
		int &next = adj[cur][i];
		if(next == past) continue;
		if(!ts[next]){
			dfs(next, cur);
			if(low[next] > ts[cur]) ans.push_back(Edge(cur, next));
			low[cur] = min(low[cur], low[next]);
		}
		else low[cur] = min(low[cur], ts[next]);
	}
}

int main()
{
	int V, E; scanf("%d %d", &V, &E);
	for(int i = 0, u, v; i < E; i++){
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for(int i = 1; i <= V; i++)
		if(!ts[i]) dfs(i, 0);

	sort(ans.begin(), ans.end());

	printf("%d\n", ans.size());
	for(int i = 0; i < ans.size(); i++)
		printf("%d %d\n", ans[i].u, ans[i].v);

	return 0;
}