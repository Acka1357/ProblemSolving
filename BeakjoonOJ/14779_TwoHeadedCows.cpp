#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

struct Edge{
	int idx, dir;
	Edge(){} Edge(int i, int d): idx(i), dir(d){}
	bool operator <(const Edge &o){
		return idx < o.idx;
	}
};

int dir[25001];
vector<Edge> adj[25001];
Edge par[25001];

Edge find(int x){
	if(par[x].idx == x) return par[x];
	Edge ret = find(par[x].idx);
	ret.dir *= par[x].dir;
	return par[x] = ret;
}

void link(int px, int py, int d){
	par[py] = Edge(px, d);
}

int main()
{
	int N, M; scanf("%d %d", &N, &M);
	char ah, bh;	
	for(int i = 0, a, b; i < M; i++){
		scanf("%d %c %d %c", &a, &ah, &b, &bh);
		int d = (ah == bh) ? -1 : 1;
		if(a > b) swap(a, b);
		adj[b].push_back(Edge(a, d));
	}

	for(int i = 1; i <= N; i++)
		par[i] = Edge(i, 1);

	int ans = 1, st = 1;
	for(int u = 2; u <= N; u++){
		Edge pu = find(u);
		for(int i = 0; i < adj[u].size(); i++){
			int v = adj[u][i].idx, d = adj[u][i].dir;
			if(v < st) continue;
			Edge pv = find(v);
			if(pu.idx == pv.idx){
				if(pu.dir != pv.dir * d){
					st = u; ans++;
					break;	
				}
			}
			else link(pu.idx, pv.idx, d * pu.dir * pv.dir);
		}
	}
	printf("%d\n", ans);

	return 0;
}
