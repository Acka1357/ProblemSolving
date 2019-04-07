//
// Created by Acka on 2017. 11. 5..
//

#include <stdio.h>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;

#define INF     0x3f3f3f3f

struct Edge{
    int to, cost, cap, rev;
    Edge(){} Edge(int to, int cost, int cap, int rev) :to(to), cost(cost), cap(cap), rev(rev){}
};

struct MCF{
    int N, mind[5001];
    vector<vector<Edge> > g;
    vector<int> past, pi;
    vector<bool> inq;
    MCF(int N) : N(N), g(vector<vector<Edge> >(N)), past(vector<int>(N)), pi(vector<int>(N)), inq(vector<bool>(N)){}

    void add_edge(int from, int to, int cost, int flow){
        g[from].push_back(Edge(to, cost, flow, g[to].size()));
        g[to].push_back(Edge(from, -cost, 0, g[from].size() - 1));
    }

    bool spfa(int src, int sink){
        memset(mind, 0x3f, N * sizeof(mind[0]));
        queue<int> q; q.push(src);
        inq[src] = true;
        mind[src] = 0;
        past[src] = src; pi[src] = -1;
        while (!q.empty()){
            int cur = q.front(); q.pop();
            inq[cur] = false;
            for (int i = 0; i < g[cur].size(); i++){
                int &next = g[cur][i].to, newc = mind[cur] + g[cur][i].cost;
                if (0 < g[cur][i].cap && newc < mind[next]){
                    mind[next] = newc;
                    past[next] = cur; pi[next] = i;
                    if (!inq[next]){
                        q.push(next); inq[next] = true;
                    }
                }
            }
        }
        return mind[sink] < INF;
    }

    pair<int, int> solve(int src, int sink){
        int sumc = 0, sumf = 0;
        while (spfa(src, sink)){
            int flow = INF, cost = 0;
            for (int cur = sink; cur != src; cur = past[cur]) {
                flow = min(flow, g[past[cur]][pi[cur]].cap);
                cost += g[past[cur]][pi[cur]].cost;
            }
            if (0 <= cost) break;

            for (int cur = sink; cur != src; cur = past[cur]){
                g[past[cur]][pi[cur]].cap -= flow;
                g[cur][g[past[cur]][pi[cur]].rev].cap += flow;
            }
            sumc += cost * flow; sumf += flow;
        }
        return make_pair(sumc, sumf);
    }
};

int main()
{
    int N, K; scanf("%d %d", &N, &K);
    if(!K) return 0 & printf("0\n");

    MCF mcf(2 * N * N);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++){
            if(j < N - 1) mcf.add_edge(2 * (i * N + j) + 1, 2 * (i * N + j + 1), 0, K);
            if(i < N - 1) mcf.add_edge(2 * (i * N + j) + 1, 2 * ((i + 1) * N + j), 0, K);
        }

    for(int i = 0, x; i < N; i++)
        for(int j = 0; j < N; j++){
            scanf("%d", &x);
            mcf.add_edge(2 * (i * N + j), 2 * (i * N + j) + 1, -x, 1);
            mcf.add_edge(2 * (i * N + j), 2 * (i * N + j) + 1, 0, K - 1);
        }

    printf("%d\n", -mcf.solve(0, 2 * N * N - 1).first);
    return 0;
}
