#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <utility>
using namespace std;

typedef long long ll;

int minv, subc[300001];
bool maxn[300001];
vector<int> adj[300001];

int dfs(int cur){
	if(adj[cur].size() == 0)
		return subc[cur] = 1;

	if(maxn[cur]){
		int need = dfs(adj[cur][0]);
		for(int i = 1; i < adj[cur].size(); i++){
			int ret = dfs(adj[cur][i]);
			if(ret < need){
				minv += need;
				need = ret;
			}
			else minv += ret;
		}
		return subc[cur] = need;
	}

	int need = 0;
	for(int &nxt : adj[cur])
		need += dfs(nxt);
	return subc[cur] = need;
}

int main()
{
	int N; scanf("%d", &N);
	for(int i = 1; i <= N; i++)
		scanf("%d", &maxn[i]);
	for(int j = 2, p; j <= N; j++){
		scanf("%d", &p);
		adj[p].push_back(j);
	}

	int ret = dfs(1);
	printf("%d\n", minv + 1);
	
	return 0;
}