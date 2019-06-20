#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int N, ans, map[500][500], ind[250000], len[250000];
int dr[] = {0, 1, 0, -1}, dc[] = {1, 0, -1, 0};
vector<int> adj[250000];

int main()
{
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			scanf("%d", &map[i][j]);

	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			for(int d = 0; d < 4; d++){
				int nr = i + dr[d], nc = j + dc[d];
				if(nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
				if(map[i][j] < map[nr][nc]){
					adj[i * N + j].push_back(nr * N + nc);
					ind[nr * N + nc]++;
				}
			}

	N = N * N;
	queue<int> q;
	for(int i = 0; i < N; i++)
		if(!ind[i]) q.push(i), len[i] = 1;
	while(!q.empty()){
		int cur = q.front(); q.pop();
		ans = len[cur];
		for(int &nxt : adj[cur])
			if(!(--ind[nxt])){
				q.push(nxt);
				len[nxt] = len[cur] + 1;
			}
	}
	printf("%d\n", ans);

	return 0;
}