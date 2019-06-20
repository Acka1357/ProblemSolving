/*
	2019 Ajou Univ. Programming Contest
	그래서 팩 주냐? - 서브태스크2
	Acka's cpp solution
	Time Complexity: O(ElogE)
*/

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;

bool chk[100001];
int N, E, d[100001][2], in[100001];
vector<int> adj[100001];

void dp(int cur){
	chk[cur] = true;

	if(cur == N){
		d[N][0] = 0;
		d[N][1] = INF;
		return ;
	}

	d[cur][0] = d[cur][1] = INF;
	vector<int> nhong(adj[cur].size());
	for(int i = 0; i < adj[cur].size(); i++){
		int& nxt = adj[cur][i];
		if(!chk[nxt]) dp(nxt);
		nhong[i] = d[nxt][1];
		d[cur][1] = min(d[cur][1], d[nxt][0]);
	}

	sort(nhong.rbegin(), nhong.rend());

	for(int i = 0; i < nhong.size(); i++)
		if(!i || nhong[i] != nhong[i - 1])
			d[cur][0] = min(d[cur][0], nhong[i] + i);
}

int main()
{
	scanf("%d %d", &N, &E);
	for(int i = 0, u, v; i < E; i++){
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		in[v]++;
	}
	
	int ans = INF;
	for(int i = 1; i <= N; i++)
		if(!in[i]){
			dp(i);
			ans = min(ans, d[i][0]);
		}
	printf("%d\n", ans < INF ? ans : -1);

	return 0;
}
