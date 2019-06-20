#include <stdio.h>
#include <vector>
#include <memory.h>
#include <stack>
using namespace std;

int ans;
stack<int> path;
int chk[100001][2], pr[100001][2];
vector<int> adj[100001];

bool dfs(int cur, int prt){
	chk[cur][prt] = pr[cur][prt] = true;
	for(int i = 0; i < adj[cur].size(); i++){
		int &nxt = adj[cur][i];
		if(pr[nxt][prt]){
			path.push(cur);
			ans = nxt;
			return true;
		}
		else if(!chk[nxt][1 - prt]){
			if(dfs(nxt, 1 - prt)){
				if(ans > 0) path.push(cur);
				if(ans == cur) ans = -1;
				return true;
			}
		}
	}
	pr[cur][prt] = false;
	return false;
}

int main()
{
	int tc; for(scanf("%d", &tc); tc--;){
		int N, M; scanf("%d %d", &N, &M);
		for(int i = 1; i <= N; i++) adj[i].clear();
		for(int i = 0, u, v; i < M; i++){
			scanf("%d %d", &u, &v);
			adj[u].push_back(v);
		}

		memset(chk, 0, (N + 1) * sizeof(chk[0]));
		memset(pr, 0, (N + 1) * sizeof(pr[0]));
		while(!path.empty()) path.pop();
		for(int i = 1; i <= N; i++){
			if(!chk[i][0]){
				if(dfs(i, 0)) break;
			}
			if(!chk[i][1]){
				if(dfs(i, 1)) break;
			}
		}
		if(!path.size()) printf("-1\n");
		else{
			for(printf("1\n%d\n", path.size()); !path.empty(); path.pop())
				printf("%d\n", path.top());
		}
	}
	return 0;
}
