#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

struct Edge{ int to, idx; };

bool chk[5005];
int V, E, C, ans[5005];
vector<Edge> adj[5005];

void dfs(int cur){
	chk[cur] = true;
	for(Edge &e : adj[cur]){
		if(ans[e.idx]) continue;
		if(chk[e.to]){
			ans[e.idx] = 2;
			C = 1;
		}
		else{
			ans[e.idx] = 1;
			dfs(e.to);
		}
	}
	chk[cur] = false;
}

int main()
{
	scanf("%d %d", &V, &E);
	for(int i = 0, u, v; i < E; i++){
		scanf("%d %d", &u, &v);
		adj[--u].push_back({--v, i});
	}

	for(int i = 0; i < V; i++)
		dfs(i);

	printf("%d\n", C + 1);
	for(int i = 0; i < E; i++)
		printf("%d%c", ans[i], " \n"[i == E - 1]);

	return 0;
}