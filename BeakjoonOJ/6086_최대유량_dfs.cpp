//
// Created by Acka on 2017. 1. 31..
//

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge{
    int to, cap, flow, ridx;
    Edge(){} Edge(int t, int c, int f, int r):to(t), cap(c), flow(f), ridx(r){}
    int pos() { return cap - flow; }
};

int src = 0, sink = 25, chk[52], chknum = 1;
vector<Edge> adj[52];

int dfs(int cur, int minf){
    if(cur == sink) return minf;
    chk[cur] = chknum;

    for(Edge &e: adj[cur]){
        if(chk[e.to] == chknum || !e.pos()) continue;

        int pushed = dfs(e.to, min(minf, e.pos()));
        if(pushed){
            e.flow += pushed;
            adj[e.to][e.ridx].flow -= pushed;
            return pushed;
        }
    }

    return 0;
}

int main()
{
    int N; scanf("%d", &N);

    char f, t;
    for(int i = 0, c; i < N; i++){
        scanf(" %c %c %d", &f, &t, &c);
        f -= ('A' <= f && f <= 'Z') ? 'A' : ('a' - 26);
        t -= ('A' <= t && t <= 'Z') ? 'A' : ('a' - 26);
        adj[f].push_back(Edge(t, c, 0, adj[t].size()));
        adj[t].push_back(Edge(f, 0, 0, adj[f].size() - 1));
    }

    int ans = 0, pushed;
    while(pushed = dfs(src, 10001)){
        ans += pushed;
        chknum++;
    }

    printf("%d\n", ans);
    return 0;
}
