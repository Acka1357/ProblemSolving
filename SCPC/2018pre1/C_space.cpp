#include <stdio.h>
#include <queue>
#include <unordered_set>
using namespace std;

unordered_set<int> adj[200001];

int main()
{
	setbuf(stdout, NULL);

	int T; scanf("%d", &T);
	for(int tc = 0; tc++ < T;){
		int N, M; scanf("%d %d", &N, &M);

		for(int i = 1; i <= N; i++)
			adj[i].clear();

		for(int i = 0, u, v; i < M; i++){
			scanf("%d %d", &u, &v);
			adj[u].insert(v);
			adj[v].insert(u);
		}

		queue<int> q;
		for(int i = 1; i <= N; i++)
			if(adj[i].size() == 2) q.push(i);

		while(!q.empty()){
			int cur = q.front(); q.pop();
			if(adj[cur].size() != 2) continue;
			
			auto it = adj[cur].begin();
			int u = *it;
			int v = *(++it);
			if(!adj[u].count(v)) continue;

			N--;
			adj[u].erase(cur);
			adj[v].erase(cur);
			if(adj[u].size() == 2) q.push(u);
			if(adj[v].size() == 2) q.push(v);
		}

		printf("Case #%d\n%d\n", tc, N);
	}
	return 0;
}