#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int SQ = 300;
const int D = 18;

vector<int> adj[100005];
int depth[100005], mind[100005], t, ft[100005], et[100005], rmq[400005][D + 1];

void dfs(int cur, int par, int d){
	rmq[t][0] = depth[cur] = d;
	ft[cur] = ++t;
	for(int &nxt : adj[cur])
		if(nxt != par){
			rmq[t][0] = d + 1;
			dfs(nxt, cur, d + 1);		
			rmq[t++][0] = d;
		}
	et[cur] = t;
}

void bfs(vector<int> &st){
	queue<int> q;
	for(int &v : st) q.push(v), mind[v] = 0;
	while(!q.empty()){
		int cur = q.front(); q.pop();
		for(int &nxt : adj[cur])
			if(mind[nxt] > mind[cur] + 1){
				mind[nxt] = mind[cur] + 1;
				q.push(nxt);
			} 
	}
}

int path_len(int u, int v){
	if(ft[u] > ft[v]) swap(u, v);
	if(et[v] <= et[u]) return depth[v] - depth[u];
	int p = 31 - __builtin_clz(ft[v] - ft[u]);
	int lcd = min(rmq[ft[u]][p], rmq[ft[v] - (1 << p)][p]);
	return depth[u] + depth[v] - 2 * lcd;
}

int main()
{
	int N, Q; scanf("%d %d", &N, &Q);
	for(int i = 1, u, v; i < N; i++){
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	memset(rmq, 0x3f, sizeof(rmq));
	dfs(1, 1, 0);

	for(int d = 1, b = 1; d < D; d++, b <<= 1)
		for(int i = 1; i <= t; i++)
			rmq[i][d] = min(rmq[i][d - 1], rmq[i + b][d - 1]);

	memset(mind, 0x3f, sizeof(mind));
	vector<int> sqv; 
	sqv.push_back(1);
	
	for(int i = 0, ir = 0; i < Q; i++, ir--){
		if(!ir){
			bfs(sqv);
			ir = SQ; sqv.clear();
		}

		int cmd, x; scanf("%d %d", &cmd, &x);
		if(cmd == 1) sqv.push_back(x);
		else{
			int ans = mind[x];
			for(int &v : sqv)
				ans = min(ans, path_len(x, v));
			printf("%d\n", ans);
		}
	}

	return 0;
}