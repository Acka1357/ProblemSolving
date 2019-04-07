#include <stdio.h>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;

#define MAXF	200001

struct Edge {
	int to, cap, flow, rev;
	Edge(int t, int c, int r) :to(t), cap(c), flow(0), rev(r) {}
	int residual() const { return cap - flow; }
};

struct NetworkFlow {
	int V;
	vector< vector<Edge> > adj;
	vector<int> levels, edges_tried;

	NetworkFlow(int V) : V(V), adj(V), levels(V), edges_tried(V) {}

	void add_edge(int u, int v, int u2v, int v2u = 0) {
		adj[u].push_back(Edge(v, u2v, adj[v].size()));
		adj[v].push_back(Edge(u, v2u, adj[u].size() - 1));
	}

	bool assign_levels(int src, int sink) {
		fill(levels.begin(), levels.end(), -1);
		queue<int> q; q.push(src);
		levels[src] = 0;
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			for (int i = 0, next; i < adj[cur].size(); i++) {
				if (levels[next = adj[cur][i].to] == -1 && 0 < adj[cur][i].residual()) {
					levels[next] = levels[cur] + 1;
					q.push(next);
				}
			}
		}
		return levels[sink] != -1;
	}

	int push_flow(int cur, int sink, int flow) {
		if (cur == sink) return flow;
		for (int& i = edges_tried[cur]; i < adj[cur].size(); i++) {
			Edge& e = adj[cur][i];
			if (0 < e.residual() && levels[e.to] == levels[cur] + 1) {
				int amt = push_flow(e.to, sink, min(flow, e.residual()));
				if (0 < amt) {
					e.flow += amt;
					adj[e.to][e.rev].flow = -e.flow;
					return amt;
				}
			}
		}
		return 0;
	}

	int max_flow(int src, int sink) {
		int sumf = 0, flow;
		while (assign_levels(src, sink)) {
			fill(edges_tried.begin(), edges_tried.end(), 0);
			while (flow = push_flow(src, sink, MAXF))
				sumf += flow;
		}
		return sumf;
	}
};

int chk[301], chkt;
vector<int> adj[301];

bool psb(int cur, int to){
	if(cur == to) return true;
	chk[cur] = chkt;
	for(int i = 0; i < adj[cur].size(); i++)
		if(chk[adj[cur][i]] != chkt){
			if(psb(adj[cur][i], to)) return true;
		}
	return false;
}

int main()
{
	int tc; for(scanf("%d", &tc); tc--;){
		int V, E; scanf("%d %d", &V, &E);
		
		int src = 1, sink = V;
		NetworkFlow nf(sink + 1);
		for(int i = 0, u, v, c; i < E; i++){
			scanf("%d %d %d", &u, &v, &c);
			nf.add_edge(u, v, c);
		}

		nf.max_flow(src, sink);
		for(int i = 1; i <= V; i++) adj[i].clear();

		int ans = chkt = 0;
		for(int i = 1; i <= V; i++)
			for(int j = 0; j < nf.adj[i].size(); j++)
				if(nf.adj[i][j].residual())
					adj[i].push_back(nf.adj[i][j].to);

		for(int i = 1; i <= V; i++)
			for(int j = 0; j < nf.adj[i].size(); j++)
				if(!nf.adj[i][j].residual() && nf.adj[i][j].cap){
					++chkt;
					ans += !psb(i, nf.adj[i][j].to);
				}

		printf("%d\n", ans);
	}
	return 0;
}
