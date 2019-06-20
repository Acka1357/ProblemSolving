//
// Created by Acka on 10/1/16.
//

#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

#define MAXF    987654321

struct Edge {
    int to, cap, flow, rev;
    Edge(int t, int c, int r):to(t), cap(c), flow(0), rev(r){}
    int residual() const {return cap - flow;}
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

int main()
{
    int dr[4] = {0, 1, 0, -1}, dc[4] = {1, 0, -1, 0};

    int N, M; scanf("%d %d", &N, &M);

    char map[100][101];
    for(int i = 0; i < N; i++)
        scanf("%s", map[i]);

    int src, sink;
    NetworkFlow mf(2 * N * M);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++){
            if(map[i][j] == 'K'){
                src = 2 * (i * M + j) + 1;
                for(int k = 0; k < 4; k++){
                    int nr = i + dr[k], nc = j + dc[k];
                    if(nr < 0 || nc < 0 || N <= nr && M <= nc) continue;
                    if(map[nr][nc] == 'H') return 0 & printf("-1\n");
                    if(map[nr][nc] == '.') mf.add_edge(src, 2 * (nr * M + nc), 1);
                }
            }
            if(map[i][j] == 'H'){
                sink = 2 * (i * M + j);
                for(int k = 0; k < 4; k++){
                    int nr = i + dr[k], nc = j + dc[k];
                    if(nr < 0 || nc < 0 || N <= nr && M <= nc) continue;
                    if(map[nr][nc] == '.') mf.add_edge(2 * (nr * M + nc) + 1, sink, 1);
                }
            }
        }

    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++){
            if(map[i][j] != '.') continue;
            mf.add_edge(2 * (i * M + j), 2 * (i * M + j) + 1, 1);
            for(int k = 0; k < 4; k++){
                int nr = i + dr[k], nc = j + dc[k];
                if(nr < 0 || nc < 0|| N <= nr || M <= nc) continue;
                if(map[nr][nc] != '.') continue;
                mf.add_edge(2 * (i * M + j) + 1, 2 * (nr * M + nc), 1);
            }
        }

    printf("%d\n", mf.max_flow(src, sink));
    return 0;
}
