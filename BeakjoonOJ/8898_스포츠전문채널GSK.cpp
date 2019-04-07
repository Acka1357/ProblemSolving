#include <stdio.h>
#include <vector>
#include <memory.h>
#include <queue>
using namespace std;

struct BTM{
	int N, step;
	vector<vector<int>> adj;
	vector<int> match, used;

	BTM(int N) : N(N), adj(N), match(vector<int>(N, -1)), used(N), step(0){}

	void add_edge(int l, int r){ adj[l].push_back(r); }

	bool dfs(int v){
		used[v] = step;
		for (int i = 0; i < adj[v].size(); i++){
			int u = adj[v][i], w = match[u];
			if (w < 0 || used[w] != step && dfs(w)){
				match[v] = u; match[u] = v;
				return true;
			}
		}
		return false;
	}

	int maxbtm(){
		int sum = 0;
		for (int v = 0; v < N; v++){
			if (match[v] == -1){
				++step;
				if (dfs(v)) sum++;
			}
		}
		return sum;
	}
};

int s[1000], d[1000], t[1000][1000];
bool chk[2000];

int main()
{
	int tc; for(scanf("%d", &tc); tc--;){
		int N; scanf("%d", &N);
		for(int i = 0; i < N; i++)
			scanf("%d", &s[i]);
		for(int i = 0; i < N; i++)
			scanf("%d", &d[i]);
		for(int i = 0; i < N; i++)
			for(int j = i; j < N; j++)
				scanf("%d", &t[i][j]);

		BTM btm(N * 2);
		for(int i = 0; i < N; i++)
			for(int j = i + 1; j < N; j++){
				if(s[i] + d[i] + t[i][j] <= s[j])
					btm.add_edge(i, N + j);
				else if(s[j] + d[j] + t[i][j] <= s[i])
					btm.add_edge(j, N + i);
			}

		memset(chk, false, sizeof(chk));
		printf("%d\n", N - btm.maxbtm());
		queue<int> q;
		for(int i = 0; i < N; i++)
			if(btm.match[i] < 0){
				chk[i] = true;
				q.push(i);
			}
		while(!q.empty()){
			int cur = q.front(); q.pop();
			if(cur < N){
				for(int &nxt : btm.adj[cur])
					if(nxt != btm.match[cur] && !chk[nxt]){
						chk[nxt] = true;
						q.push(nxt);
					}
			}
			else if(btm.match[cur] >= 0 && !chk[btm.match[cur]]){
				chk[btm.match[cur]] = true;
				q.push(btm.match[cur]);
			}
		}

		for(int i = 0; i < N; i++)
			if(chk[i] && !chk[N + i]) printf("%d ", i + 1);
		printf("\n");
	}
	return 0;
}
