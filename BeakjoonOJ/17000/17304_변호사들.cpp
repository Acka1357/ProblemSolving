/*
	2019 경인지역 6개대학 연합 프로그래밍 경시대회 shake!
	Acka's cpp solution - lawyer
	Time Complexity: O(M * logM)
*/

#include <cstdio>
#include <vector>
#include <set>
#include <iterator>
#include <queue>
using namespace std;

int ind[200001], par[200001], vcnt[200001], ecnt[200001];
set<int> adj[200001];

int find(int x){
	return x == par[x] ? x : (par[x] = find(par[x]));
}

void link(int x, int y){
	int px = find(x), py = find(y);
	ecnt[px]++;
	if(px == py) return ;
	par[py] = px;
	vcnt[px] += vcnt[py];
	ecnt[px] += ecnt[py];
}

int main()
{
	int N, M; scanf("%d %d", &N, &M);
	for(int i = 0, u, v; i < M; i++){
		scanf("%d %d", &u, &v);
		adj[u].insert(v);
	}

	int ans = 0;
	for(int i = 1; i <= N; i++)
		for(auto it = adj[i].begin(); it != adj[i].end();){
			auto nxt = next(it, 1);
			auto rev = adj[*it].find(i);
			if(rev == adj[*it].end()){
				if(ind[*it]++ == 0) ans++;
				adj[i].erase(it);
			}
			it = nxt;
		}

	queue<int> q;
	for(int i = 1; i <= N; i++)
		if(ind[i] && adj[i].size())
			q.push(i);

	while(!q.empty()){
		int cur = q.front(); q.pop();
		for(int nxt : adj[cur]){
			adj[nxt].erase(cur);
			if(ind[nxt]++ == 0){
				q.push(nxt);
				ans++;
			}
		}
		adj[cur].clear();
	}

	for(int i = 1; i <= N; i++)
		par[i] = i, vcnt[i] = 1;

	for(int i = 1; i <= N; i++)
		for(auto it : adj[i])
			link(i, it);

	for(int i = 1; i <= N; i++)
		if(par[i] == i && ecnt[i] >= 2 * vcnt[i])
			ans += vcnt[i];

	printf("%s\n", ans == N ? "YES" : "NO");
	
	return 0;
}