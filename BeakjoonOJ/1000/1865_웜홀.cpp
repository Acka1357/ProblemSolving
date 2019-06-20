#include <stdio.h>
#include <memory.h>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;

struct Edge{ int from, to, cost; };

int N, M, W,d[501], adj[501][501];

bool ex(){
    memset(adj, 0x3f, sizeof adj);
    memset(d, 0x3f, sizeof d);

    scanf("%d %d %d", &N, &M, &W);
    for(int i = 0, u, v, c; i < M; i++){
        scanf("%d %d %d", &u, &v, &c);
        adj[u][v] = adj[v][u] = min(adj[u][v], c);
    }
    for(int i = 0, u, v, c; i < W; i++){
        scanf("%d %d %d", &u, &v, &c);
        adj[u][v] = min(adj[u][v], -c);
    }

    vector<Edge> edge;
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            if(adj[i][j] != INF) 
                edge.push_back({i, j, adj[i][j]});

    for(int step = 0; step <= N; step++){
        bool upd = false;
        for(Edge &e : edge)
            if(d[e.to] > d[e.from] + e.cost){
                d[e.to] = d[e.from] + e.cost;
                upd = true;
            }
        if(!upd) return false;
    }

    return true;
}

int main()
{
    int tc; for(scanf("%d", &tc); tc--;){
        printf("%s\n", ex() ? "YES" : "NO");
    }
    return 0;
}
