#include <stdio.h>
#include <vector>
using namespace std;

bool cutv[10001];
int ans_cnt, t, ts[10001], low[10001];
vector<int> adj[10001];

void dfs(int cur, int past){
	ts[cur] = low[cur] = ++t;
	int child = 0;
	for(int i = 0; i < adj[cur].size(); i++){
		if(!ts[adj[cur][i]]){
			dfs(adj[cur][i], cur), child++;
			low[cur] = min(low[cur], low[adj[cur][i]]);
			if(low[adj[cur][i]] >= ts[cur])
				cutv[cur] = true;
		}
		if(0 < ts[adj[cur][i]])
			low[cur] = min(low[cur], ts[adj[cur][i]]);
	}
	if(!past) cutv[cur] = child > 1;
	if(cutv[cur]) ans_cnt++;
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

	printf("%d\n", ans_cnt);
	for(int i = 1; i <= V; i++)
		if(cutv[i]) printf("%d ", i);
	printf("\n");

	return 0;
}