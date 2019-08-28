#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int D = 17;

vector<int> adj[100005];
int depth[100005], ts, in[100005], out[100005], tv[100005], anc[D + 1][200005];
vector<int> has[100005], ahas[D + 1][200005];

void dfs(int cur, int par){
	in[cur] = ++ts;
	anc[0][cur] = par;
	depth[cur] = depth[par] + 1;
	for(int &nxt : adj[cur])
		if(nxt != par) dfs(nxt, cur);
	out[cur] = ts;
}

void merge(vector<int> &a, vector<int> &b, vector<int> &res){
	int ai = 0, bi = 0, ri = 0;
	vector<int> tmp;
	while(ai < a.size() && bi < b.size() && tmp.size() < 10){
		if(a[ai] < b[bi]) tmp.push_back(a[ai++]);
		else if(a[ai] > b[bi]) tmp.push_back(b[bi++]); 
		else tmp.push_back(a[ai++]), bi++;
	}
	while(ai < a.size() && tmp.size() < 10) tmp.push_back(a[ai++]);
	while(bi < b.size() && tmp.size() < 10) tmp.push_back(b[bi++]);
	res = tmp;
}

void gathering(int u, int v, vector<int> &ans){
	if(depth[u] < depth[v]) swap(u, v);
	merge(has[u], has[v], ans);
	int gap = depth[u] - depth[v];
	for(int i = 0, b = 1; gap; i++, b <<= 1)
		if(gap & b){
			merge(ahas[i][u], ans, ans);
			u = anc[i][u];
			gap -= b;
		}
	if(u == v) return ;
	for(int i = D; i >= 0; i--){
		if(anc[i][u] == anc[i][v]) continue;
		merge(ahas[i][u], ans, ans);
		merge(ahas[i][v], ans, ans);
		u = anc[i][u], v = anc[i][v];
	}
	merge(ahas[0][u], ans, ans);
}

int main()
{
	int N, M, Q; scanf("%d %d %d", &N, &M, &Q);
	for(int i = 1, u, v; i < N; i++){
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i = 1, x; i <= M; i++){
		scanf("%d", &x);
		has[x].push_back(i);
	}

	dfs(1, 0);

	for(int i = 1; i <= N; i++) sort(has[i].begin(), has[i].end());
	for(int i = 1; i <= N; i++)
		merge(has[anc[0][i]], ahas[0][i], ahas[0][i]);

	for(int i = 1; i <= D; i++)
		for(int j = 1; j <= N; j++){
			anc[i][j] = anc[i - 1][anc[i - 1][j]];
			merge(ahas[i - 1][j], ahas[i - 1][anc[i - 1][j]], ahas[i][j]);
		}

	for(int i = 0; i < Q; i++){
		int u, v, a; scanf("%d %d %d", &u, &v, &a);
		vector<int> ans;
		gathering(u, v, ans);
		int cnt = min((int)ans.size(), a);
		printf("%d%c", cnt, " \n"[!cnt]);
		for(int j = 0; j < cnt; j++)
			printf("%d%c", ans[j], " \n"[j == cnt - 1]);
	}

	return 0;
}