#include <stdio.h>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

char t[2][3001], a[2][1001];
int d[1001][1001], si[2], idx[2], cnt[2][1001], sd[1001][1001];
vector<int> adj[2][1001];

void make_tree(int tn, int par){
	int cur = ++idx[tn]; adj[tn][cur].clear();
	a[tn][cur] = t[tn][si[tn]++];
	if(par) adj[tn][par].push_back(cur);
	while(t[tn][si[tn]++] != ')')
		make_tree(tn, cur);
	cnt[tn][par] += ++cnt[tn][cur];
	return ;
}

int calc_min(int v1, int v2){
	int c1 = adj[0][v1].size(), c2 = adj[1][v2].size();
	for(int i = 0; i < c1; i++)
		for(int j = 0; j < c2; j++)
			calc_min(adj[0][v1][i], adj[1][v2][j]);
	
	sd[0][0] = 0;
	for(int i = 0; i <= c1; i++)
		for(int j = 0; j <= c2; j++){
			if(i || j) sd[i][j] = 0x3f3f3f3f;
			if(i && j) sd[i][j] = sd[i - 1][j - 1] + d[adj[0][v1][i - 1]][adj[1][v2][j - 1]];
			if(i) sd[i][j] = min(sd[i][j], sd[i - 1][j] + cnt[0][adj[0][v1][i - 1]]);
			if(j) sd[i][j] = min(sd[i][j], sd[i][j - 1] + cnt[1][adj[1][v2][j - 1]]);
		}

	return d[v1][v2] = sd[c1][c2] + (a[0][v1] != a[1][v2]);
}

int main()
{
	setbuf(stdout, NULL);
	int tc; for(scanf("%d", &tc); tc--;){
		si[0] = si[1] = 1;
		idx[0] = idx[1] = 0;
		scanf("%s %s", t[0], t[1]);
		memset(cnt, 0, sizeof(cnt));
		make_tree(0, 0); make_tree(1, 0);
		printf("%d\n", calc_min(1, 1));
	}
	return 0;
}
