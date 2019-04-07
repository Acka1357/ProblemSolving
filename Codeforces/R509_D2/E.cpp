#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <assert.h>
using namespace std;

queue<int> q;
vector<int> dist[1001];
int cnt[1001], ans[1000][2];

int par[1001];

int find(int x){
	return par[x] == x ? x : (par[x] = find(par[x]));
}

void link(int x, int y){
	par[find(x)] = find(y);
}

int main()
{
	int N; scanf("%d", &N);
	for(int i = 1, u, v; i < N; i++){
		scanf("%d %d", &u, &v);
		cnt[u]++; cnt[v]++;
	}

	if(cnt[N] != N - 1|| !cnt[N - 1]) return !printf("NO\n");

	int sum = 0;
	for(int i = 1; i < N; i++){
		sum += cnt[i];
		if(sum > i) return !printf("NO\n");
		dist[cnt[i]].push_back(i);
	}

	int zidx = 0, aidx = 0, lvc = N - dist[0].size() - dist[1].size() - 1;
	for(int i = 0; i < dist[1].size(); i++){
		ans[aidx][0] = N;
		ans[aidx][1] = dist[1][i];
		aidx++;
	}
	for(int i = 0; i < lvc; i++){
		if(zidx == dist[0].size()) return !printf("NO\n");
		ans[aidx][0] = N;
		ans[aidx][1] = dist[0][zidx];
		q.push(dist[0][zidx++]);
		aidx++;
	}

	for(int i = 2; i < N; i++){
		for(int j = 0; j < dist[i].size(); j++){
			ans[aidx][0] = q.front(); q.pop();
			ans[aidx][1] = dist[i][j];
			aidx++;
		}
		lvc -= dist[i].size();
		for(int j = 0; j < lvc; j++){
			if(zidx == dist[0].size()) return !printf("NO\n");
			ans[aidx][0] = q.front(); q.pop();
			ans[aidx][1] = dist[0][zidx];
			q.push(dist[0][zidx++]);
			aidx++;
		}
	}

	assert(aidx == N - 1);

	for(int i = 1; i <= N; i++)
		par[i] = i;
	for(int i = 0; i < aidx; i++){
		if(ans[i][0] == ans[i][1]) return 0;
		if(find(ans[i][0]) == find(ans[i][1])){
			while(true);
		}
		link(ans[i][0], ans[i][1]);
	}

	printf("YES\n");
	for(int i = 0; i < aidx; i++)
		printf("%d %d\n", ans[i][0], ans[i][1]);

	return 0;
}
