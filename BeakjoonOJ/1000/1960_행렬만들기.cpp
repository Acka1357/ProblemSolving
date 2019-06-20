#include <stdio.h>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;

#define MAXF	987654321

struct Edge {
	int to, cap, flow, rev;
	Edge(int t, int c, int r) :to(t), cap(c), flow(0), rev(r) {}
	int residual() const { return cap - flow; }
};

struct NetworkFlow {
	int V;
	vector<vector<Edge>> adj;
	vector<int> levels, edges_tried;

	NetworkFlow(int V): V(V), adj(V), levels(V), edges_tried(V) {}

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

char ans[501][502];
int r[501], c[501], cumr[501], cumc[501];

int main()
{
	int N; scanf("%d", &N);
	for(int i = 1; i <= N; i++){
		scanf("%d", &r[i]);
		if(r[i] > N) return !printf("-1\n");
		cumr[i] = cumr[i - 1] + r[i];
	}
	for(int i = 1; i <= N; i++){
		scanf("%d", &c[i]);
		if(c[i] > N) return !printf("-1\n");
		cumc[i] = cumc[i - 1] + c[i];
	}
	if(cumr[N] != cumc[N]) return !printf("-1\n");

	int src = 0, sink = 2 * N + 1;
	NetworkFlow nf(sink + 1);
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++)
			nf.add_edge(i, N + j, 1);
		nf.add_edge(src, i, r[i]);
		nf.add_edge(N + i, sink, c[i]);
	}
	
	if(nf.max_flow(src, sink) != cumr[N]) return !printf("-1\n");

	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= N; j++)
			ans[i][j] = '0' + (nf.adj[i][j - 1].residual() == 0);

	printf("1\n");
	for(int i = 1; i <= N; i++)
		printf("%s\n", ans[i] + 1);

	return 0;
}
