//
// Created by Acka on 9/30/16.
//

#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

#define MAXF	987654321
#define MAXN    2502

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

int main()
{
    int dr[4] = {0, 1, 0, -1}, dc[4] = {1, 0, -1, 0};
    int ci[256] = {0,}, cost[5][5] = {{10, 8, 7, 5, 1},
                                      {8, 6, 4, 3, 1},
                                      {7, 4, 3, 2, 1},
                                      {5, 3, 2, 2, 1},
                                      {1, 1, 1, 1, 0}};
    ci['A'] = 0; ci['B'] = 1; ci['C'] = 2; ci['D'] = 3; ci['F'] = 4;

    int N, M; scanf("%d %d", &N, &M);

    char map[50][51];
    for(int i = 0; i < N; i++)
        scanf("%s", map[i]);

    int src = 0, sink = N * M + 1;
    MinCostFlow mcf(sink + 1);
    for(int i = 0, cur = 1; i < N; i++)
        for(int j = 0; j < M; j++, cur++){
            if((i + j) & 1){
                mcf.add_edge(src, cur, 0, 1);
                for(int k = 0; k < 4; k++){
                    int nr = i + dr[k], nc = j + dc[k];
                    if(0 <= nr && 0 <= nc && nr < N && nc < M)
                        mcf.add_edge(cur, nr * M + nc + 1, -cost[ci[map[i][j]]][ci[map[nr][nc]]], 1);
                }
            }
            else mcf.add_edge(cur, sink, 0, 1);
        }

    printf("%d\n", -(mcf.solve(src, sink, 0).first));
    return 0;
}
 