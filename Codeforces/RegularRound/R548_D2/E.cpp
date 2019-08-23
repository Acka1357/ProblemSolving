#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <stack>
#include <utility>
using namespace std;

typedef long long ll;

bool ex[5001], chk[5001][5001];
int N, M, D, p[5001], c[5001], d[5001], aq[5001];
vector<int> pc[5001];

struct BTM {
	int N, step;
	vector<vector<int> > G;
	vector<int> match, used;

	BTM(int N) : N(N), G(N), match(vector<int>(N, -1)), used(N), step(0) {}

	void add_edge(int l, int r) { G[l].push_back(r); }

	bool dfs(int v) {
		used[v] = step;
		for (int i = 0; i < G[v].size(); i++) {
			int u = G[v][i], w = match[u];
			if (w < 0 || used[w] != step && dfs(w)) {
				match[v] = u; match[u] = v;
				return true;
			}
		}
		return false;
	}

	int maxbtm() {
		int sum = 0;
		for (int v = 0; v < N; v++) {
			if (match[v] == -1) {
				++step;
				if (dfs(v)) sum++;
			}
		}
		return sum;
	}
};

int main()
{
	scanf("%d %d", &N, &M);
	for(int i = 1; i <= N; i++)
		scanf("%d", &p[i]);
	for(int i = 1; i <= N; i++){
		scanf("%d", &c[i]);
		c[i]--;
	}
	scanf("%d", &D);
	for(int i = 1; i <= D; i++)
		scanf("%d", &d[i]);
	
	for(int i = 1; i<= N; i++)
		ex[i] = true;
	for(int i = 1; i <= D; i++)
		ex[d[i]] = false;

	for(int i = 1; i <= N; i++)
		if(ex[i] && !chk[c[i]][p[i]]){
			chk[c[i]][p[i]] = true;
			pc[p[i]].push_back(c[i]);
		}

	int l = 0, r = 5000, m, ans = 0, ai = D;
	while(l <= r){
		m = (l + r) / 2;
		BTM btm(M + 5001);
		for(int i = 0; i < m; i++)
			for(int j = 0; j < pc[i].size(); j++)
				btm.add_edge(pc[i][j], M + i);

		int b = btm.maxbtm();
		// printf("[??]%d %d: %d / %d\n", l, r, m, b);
		if(b >= m){
			ans = m;
			l = m + 1;
		}
		else r = m - 1;
	}
	aq[ai--] = ans;
	
	queue<int> q[5001];	
	memset(chk, 0, sizeof(chk));
	for(int i = 1; i <= N; i++)
		if(ex[i] && !chk[c[i]][p[i]]){
			chk[c[i]][p[i]] = true;
			q[p[i]].push(c[i]);
		}

	BTM btm(M + 5001);
	for(int i = 0; i < ans; i++)
		while(!q[i].empty()){
			// printf("pre: %d->%d\n", q[i].front(), i);
			btm.add_edge(q[i].front(), M + i);
			q[i].pop();
		}
	btm.maxbtm();

	bool upd = false;
	while(!q[ans].empty()){
		upd = true;
		btm.add_edge(q[ans].front(), M + ans);
		q[ans].pop();
	}
	ans++;

	for(int i = D; i > 1; i--){
		if(ans < N){
			int cur = d[i];
			if(!chk[c[cur]][p[cur]]){
				chk[c[cur]][p[cur]] = true;
				if(p[cur] >= ans) q[p[cur]].push(c[cur]);
				else{
					upd = true;
					btm.add_edge(c[cur], M + p[cur]);
				}
			}

			while(btm.maxbtm() && upd){
				upd = false;
				while(!q[ans].empty()){
					upd = true;
					btm.add_edge(q[ans].front(), M + ans);
					q[ans].pop();
				}
				ans++;
			}
			btm.step--;
		}
		aq[ai--] = ans - 1;
	}

	for(int i = 1; i <= D; i++)
		printf("%d\n", aq[i]);

	return 0;
}
