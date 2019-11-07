#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
#include <cassert>
using namespace std;

set<int> adj[100005];
bool chk[100005];
int par[100005];

int find(int x){
	return x == par[x] ? x : (par[x] = find(par[x]));
}

bool link(int x, int y){
	int px = find(x), py = find(y);
	if(px == py) return false;
	par[py] = px;
	return true;
}

int main()
{
	int N, M; scanf("%d %d", &N, &M);
	for(int i = 0, u, v; i < M; i++){
		scanf("%d %d", &u, &v);
		adj[u].insert(v);
		adj[v].insert(u);
	}

	int cnt = 0;
	queue<int> uncov;
	for(int i = 1; i <= N; i++)
		par[i] = i, uncov.push(i);

	for(int i = 1; i <= N; i++){
		if(chk[i]) continue;
		queue<int> cov; cov.push(i); chk[i] = true;
		while(!cov.empty()){
			int cur = cov.front(); cov.pop();
			int len = uncov.size();
			for(int i = 0; i < len; i++){
				int nxt = uncov.front(); uncov.pop();
				if(chk[nxt]) continue;
				if(adj[cur].count(nxt)) uncov.push(nxt);
				else{
					assert(link(cur, nxt));
					cnt++;
					chk[nxt] = true;
					cov.push(nxt);
				}
			}
		}
	}

	printf("%d\n", N - cnt - 1);

	return 0;
}