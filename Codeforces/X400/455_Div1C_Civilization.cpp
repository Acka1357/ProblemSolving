#include <cstdio>
#include <vector>
using namespace std;

int par[300005], len[300005];
vector<int> adj[300005], g;

int find(int x){
	return par[x] == x ? x : (par[x] = find(par[x]));
}

void link(int x, int y){
	int px = find(x), py = find(y);
	if(px == py) return ;
	if(len[px] < len[py]) swap(px, py);
	par[py] = px;
	len[px] = max(len[px], (len[px] + 1) / 2 + (len[py] + 1) / 2 + 1);
}

int dfs(int cur, int p, int root){
	int l1 = 0, l2 = 0;
	for(int nxt : adj[cur]){
		if(nxt == p) continue;
		int l = dfs(nxt, cur, root) + 1;
		if(l > l1) l2 = l1, l1 = l;
		else if(l > l2) l2 = l;
	}

	par[cur] = root;
	len[root] = max(len[root], l1 + l2);
	return l1;
}

int main()
{
	int N, M, Q; scanf("%d %d %d", &N, &M, &Q);
	for(int i = 0, u, v; i < M; i++){
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for(int i = 1; i <= N; i++)
		par[i] = i;
	for(int i = 1; i <= N; i++)
		if(par[i] == i)
			dfs(i, i, i);

	while(Q--){
		int cmd, x, y; scanf("%d", &cmd);
		if(cmd == 1){
			scanf("%d", &x);
			printf("%d\n", len[find(x)]);
		}
		else{
			scanf("%d %d", &x, &y);
			link(x, y);
		}
	}

	return 0;	
}