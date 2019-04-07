#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <utility>
#include <memory.h>
using namespace std;

#define MAXV		100001

struct Edge{
	int to, dist;
	Edge(int t, int d): to(t), dist(d){}
}

int N, anc[MAXV][20], in[MAXV], out[MAXV], t, last[MAXV], anidx[MAXV];
vector<int> an;
vector<Edge> adj[MAXV], apath[22];
long long rootd[MAXV], sumd[MAXV];


void set_rootd(int cur, int par, long long int d){
	anc[cur][0] = par;
	for (int i = 1, p = par; anc[cur][i - 1]; p = anc[cur][i++])
		anc[cur][i] = anc[p][i - 1];
	in[cur] = ++t;
	rootd[cur] = d;
	for (int i = 0; i < adj[cur].size(); i++){
		int &next = adj[cur][i].to;
		if(next != par && in[next] && rootd[next] - rootd[cur] > adj[cur][i].dist){
			if(!anidx[cur]){
				anidx[cur] = an.size();
				an.push_back(cur);
			}
			apath[anidx[cur]].push_back(Edge(next, adj[cur][i].dist - rootd[next] + rootd[cur]));
		}
		else if(next != par)
			set_rootd(next, cur, d + adj[cur][i].dist);
	}
	out[cur] = ++t;
}

int get_lca(int u, int v){
	if (in[u] <= in[v] && out[v] <= out[u]) return u; 
	if (in[v] <= in[u] && out[u] <= out[v]) return v;
	for (int i = 19; 0 <= i; i--)
		if (in[v] < in[anc[u][i]] || out[anc[u][i]] < out[v])
			u = anc[u][i];
	return anc[u][0];
}

struct Node{
	int cur;
	long long dec;
	bool operator <(const Node &o)const{
		return dec < o.dec;
	}
};

int chkt;
int chkchk[MAXV], mind[MAXV];

long long find_dec(int from, int to){
	priority_queue<Node> q;
	q.push(Node(from, 0));
	long long ret = 0;
	while(!q.empty()){
		int cur = q.top();
		long long dec = q.top(); q.pop();
	}
	return ret;
}

int main()
{
	int N, M; scanf("%d %d", &N, &M);
	for(int i = 0, u, v, d; i < M; i++){
		scanf("%d %d %d", &u, &v, &d);
		adj[u].push_back(Edge(v, d));
		adj[v].push_back(Edge(u, d));
	}

	set_rootd(1, 0, 0);

	int Q; scanf("%d", &Q);
	for(int u, v; Q--;){
		scanf("%d %d", &u, &v);
		int lca = get_lca(u, v);
		printf("%lld\n", 2 * rootd[lca] - rootd[u] - rootd[v] + find_dec(u, lca) + find_dec(v, lca));
	}
	return 0;
}
