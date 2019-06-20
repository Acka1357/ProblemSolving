//
// Created by Acka on 2017. 1. 2..
//

#include <stdio.h>
#include <vector>
#include <memory.h>
#include <queue>
using namespace std;

struct Edge{
    int v, c;
    Edge(){} Edge(int v, int c):v(v), c(c){}
    bool operator <(const Edge &o)const{
        return o.c < c;
    }
};

int mind[20001];
bool chk[20001];
vector<Edge> adj[20001];

int main()
{
    int V, E, S; scanf("%d %d %d", &V, &E, &S);
    for(int i = 0, u, v, c; i < E; i++){
        scanf("%d %d %d", &u, &v, &c);
        adj[u].push_back(Edge(v, c));
    }

    priority_queue<Edge> q; q.push(Edge(S, 0));
    memset(mind, 0x3f, sizeof(mind));
    mind[S] = 0;
    while(!q.empty()){
        int cur = q.top().v, cost = q.top().c; q.pop();
        if(chk[cur]) continue;
        else chk[cur] = true;

        for(int i = 0; i < adj[cur].size(); i++){
            int next = adj[cur][i].v, nc = mind[cur] + adj[cur][i].c;
            if(nc < mind[next]){
                mind[next] = nc;
                q.push(Edge(next, nc));
            }
        }
    }

    for(int i = 1; i <= V; i++){
        if(0x3f3f3f3f <= mind[i]) printf("INF\n");
        else printf("%d\n", mind[i]);
    }

    return 0;
}
