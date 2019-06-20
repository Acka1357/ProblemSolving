#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

struct Edge{
	int v, c;
	Edge(int v, int c):v(v), c(c){}
};

ll ans;
int N, D;
vector<Edge> adj[40001];

int dfs(int cur, int par){
	int ci = 2;
	vector<int> half(adj[cur].size() + ci - (cur != par), 0);
	for(int i = 0; i < adj[cur].size(); i++)
		if(adj[cur][i].v != par)
			half[ci++] = dfs(adj[cur][i].v, cur) + adj[cur][i].c;
			
	sort(half.begin(), half.end());
	if(half[ci - 1] + half[ci - 2] <= D) return half[ci - 1];

	int d = max(D / 2, D - half[ci - 2]);
	for(int i = 2; i < ci; i++)
		if(half[i] > d) ans += half[i] - d;

	return d;
}

int main()
{
	int tc; for(scanf("%d", &tc); tc--;){
		scanf("%d %d", &N, &D); D <<= 1;
		for(int i = 1; i <= N; i++)
			adj[i].clear();
		for(int i = 1, u, v, c; i < N; i++){
			scanf("%d %d %d", &u, &v, &c);
			adj[u].push_back(Edge(v, c << 1));
			adj[v].push_back(Edge(u, c << 1));
		}

		ans = 0;
		dfs(1, 1);

		printf("%lld.%c\n", ans / 2, (ans & 1) ? '5' : '0');
	}
	return 0;
}
