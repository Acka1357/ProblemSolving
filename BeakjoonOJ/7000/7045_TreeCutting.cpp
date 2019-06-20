#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> adj[10001], ans;

int dfs(int cur, int p){
	int cmax = 0, csum = 0, ret;
	for(int i = 0; i < adj[cur].size(); i++){
		if(adj[cur][i] == p) continue;
		ret = dfs(adj[cur][i], cur);
		cmax = max(cmax, ret);
		csum += ret;
	}

	if(max(cmax, N - ++csum) <= N / 2)
		ans.push_back(cur);

	return csum;
}

int main()
{
	scanf("%d", &N);
	for(int i = 1, u, v; i < N; i++){
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1, 0);

	if(ans.empty()) return !printf("NONE\n");

	sort(ans.begin(), ans.end());
	for(int i = 0; i < ans.size(); i++)
		printf("%d\n", ans[i]);

	return 0;
}
