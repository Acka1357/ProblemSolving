//
// Created by Acka on 2017. 8. 8..
//

#include <stdio.h>
#include <queue>
#include <vector>
#include <memory.h>
#include <algorithm>
using namespace std;

#define INF     0x3f3f3f3f

struct Edge{
    int to, cost;
    Edge(int t, int c):to(t), cost(c){}
    bool operator <(const Edge &A)const{
        return cost > A.cost;
    }
};

vector<Edge> adj[501];
int N, M, Q, add[501], d[501][501], mind[501];

void dijkstra(int mid){
    memset(mind, 0x3f, sizeof(mind));

    priority_queue<Edge> q;
    q.push(Edge(mid, 0));
    mind[mid] = 0;
    while(!q.empty()){
        int cur = q.top().to, cost = q.top().cost; q.pop();
        if(mind[cur] < cost) continue;
        for(int i = 0; i < adj[cur].size(); i++){
            int next = adj[cur][i].to;
            int newc = cost + adj[cur][i].cost;
            if(mind[next] > newc && add[next] <= add[mid]){
                mind[next] = newc;
                q.push(Edge(next, newc));
            }
        }
    }

    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            d[i][j] = min(d[i][j], mind[i] + mind[j] + add[mid]);
}

int main()
{
    memset(d, 0x3f, sizeof(d));

    scanf("%d %d %d", &N, &M, &Q);
    for(int i = 1; i <= N; i++)
        scanf("%d", &add[i]);

    for(int i = 0, u, v, c; i < M; i++){
        scanf("%d %d %d", &u, &v, &c);
        adj[u].push_back(Edge(v, c));
        adj[v].push_back(Edge(u, c));
    }

    for(int start = 1; start <= N; start++)
        dijkstra(start);

    int S, T;
    while(Q--){
        scanf("%d %d", &S, &T);
        printf("%d\n", d[S][T] >= INF ? -1 : d[S][T]);
    }

    return 0;
}
