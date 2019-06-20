#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

vector<int> adj[1001];
int s[101];
bool rc[101][1001];

int main()
{
	int N, V, E; scanf("%d %d %d", &N, &V, &E);
	for(int i = 1; i <= N; i++)
		scanf("%d", &s[i]);
	for(int i = 0, u, v; i < E; i++){
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
	}

	for(int i = 1; i <= N; i++){
		bool *chk = rc[i];
		queue<int> q; 
		q.push(s[i]); chk[s[i]] = true;
		while(!q.empty()){
			int cur = q.front(); q.pop();
			for(int nxt : adj[cur])
				if(!chk[nxt]){
					q.push(nxt);
					chk[nxt] = true;
				}
		}
	}

	int ans = 0;
	for(int i = 1; i <= V; i++){
		bool chk = true;
		for(int j = 1; j <= N; j++)
			if(!rc[j][i]) chk = false;
		ans += chk;
	}
	printf("%d\n", ans);

	return 0;
}
