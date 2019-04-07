//
// Created by Acka on 10/24/16.
//

#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

#define MAXF	987654321
#define MAXN    452

struct Edge{
    int to, cost, cap, rev;
    Edge(){} Edge(int to, int cost, int cap, int rev):to(to), cost(cost), cap(cap), rev(rev){}
};

struct MinCostFlow{
    int N, mind[MAXN];
    vector<vector<Edge> > G;
    vector<int> path, pathi;
    vector<bool> inq;
    MinCostFlow(int N): N(N), G(vector<vector<Edge> >(N)), path(vector<int>(N)), pathi(vector<int>(N)), inq(vector<bool>(N)){}

    void add_edge(int from, int to, int cost, int flow){
        G[from].push_back(Edge(to, cost, flow, G[to].size()));
        G[to].push_back(Edge(from, -cost, 0, G[from].size() - 1));
    }

    bool spfa(int src, int sink){
        memset(mind, 0x3f, N * sizeof(mind[0]));
        queue<int> q; q.push(src);
        mind[src] = 0; inq[src] = true;
        path[src] = src; pathi[src] = -1;
        while(!q.empty()){
            int cur = q.front(); q.pop();
            inq[cur] = false;
            for(int i = 0; i < G[cur].size(); i++){
                int next = G[cur][i].to, newc = mind[cur] + G[cur][i].cost;
                if(0 < G[cur][i].cap && newc < mind[next]){
                    mind[next] = newc;
                    path[next] = cur; pathi[next] = i;
                    if(!inq[next]){
                        q.push(next); inq[next] = true;
                    }
                }
            }
        }
        return mind[sink] < 0x3f3f3f3f;
    }

    pair<int, int> solve(int src, int sink, int minf = MAXF){
        int sumc = 0, sumf = 0;
        while(spfa(src, sink)){
            int flow = MAXF, cost = 0;
            for(int cur = sink; cur != src; cur = path[cur]) {
                flow = min(flow, G[path[cur]][pathi[cur]].cap);
                cost += G[path[cur]][pathi[cur]].cost;
            }
            if(minf <= sumf && 0 <= cost) break;

            for(int cur = sink; cur != src; cur = path[cur]){
                G[path[cur]][pathi[cur]].cap -= flow;
                G[cur][G[path[cur]][pathi[cur]].rev].cap += flow;
            }
            sumc += cost * flow; sumf += flow;
        }
        return make_pair(sumc, sumf);
    }
};

char dir[4] = {'U', 'L', 'D', 'R'};
int dr[26], dc[26];

int main()
{
    dr['U' - 'A'] = dc['L' - 'A'] = -1;
    dr['D' - 'A'] = dc['R' - 'A'] = 1;

    int N, M; scanf("%d %d", &N, &M);

    char map[15][16];
    for(int i = 0; i < N; i++)
        scanf("%s", map[i]);

    int src = 0, sink = N * M * 2 + 1;
    MinCostFlow mcf(sink + 1);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++){
            for(int k = 0; k < 4; k++){
                int nr = (i + dr[dir[k] - 'A'] + N) % N, nc = (j + dc[dir[k] - 'A'] + M) % M;
                mcf.add_edge(i * M + j + 1, (N + nr) * M + nc + 1, dir[k] != map[i][j], 1);
            }
            mcf.add_edge(src, i * M + j + 1, 0, 1);
            mcf.add_edge((N + i) * M + j + 1, sink, 0, 1);
        }

    printf("%d\n", mcf.solve(src, sink, N * M).first);
    return 0;
}
