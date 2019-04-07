#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXF = 0x3f3f3f3f;
typedef long long ll;

struct Edge {
	int to, cap, flow, rev;
	Edge(int t, int c, int r) :to(t), cap(c), flow(0), rev(r) {}
	int residual() const { return cap - flow; }
};

struct Dinic {
	int V;
	vector< vector<Edge> > adj;
	vector<int> levels, edges_tried;

	Dinic(int V) : V(V), adj(V), levels(V), edges_tried(V) {}

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

	ll max_flow(int src, int sink) {
		ll sumf = 0, flow;
		while (assign_levels(src, sink)) {
			fill(edges_tried.begin(), edges_tried.end(), 0);
			while (flow = push_flow(src, sink, MAXF))
				sumf += flow;
		}
		return sumf;
	}
};

int main()
{
	int N, M; scanf("%d %d", &N, &M);

	int src = 0, sink = N + M + 1;
	Dinic flow(sink + 1);
	for(int i = 1, c; i <= N; i++){
		scanf("%d", &c);
		flow.add_edge(src, i, c);
	}

	ll sum = 0;
	for(int i = 1, u, v, c; i <= M; i++){
		scanf("%d %d %d", &u, &v, &c);
		flow.add_edge(u, N + i, MAXF);
		flow.add_edge(v, N + i, MAXF);
		flow.add_edge(N + i, sink, c);
		sum += c;
	}
	printf("%lld\n", sum - flow.max_flow(src, sink));

	return 0;
}