//
// Created by Acka on 2016. 12. 8..
//

#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

struct Edge{
    int to, cost;
    Edge(){} Edge(int v, int c):to(v), cost(c){}
    bool operator < (const Edge &A)const{
        return A.cost < cost;
    }
};

vector<Edge> adj[1001];
priority_queue<int> mind[1001];
int cnt[1001];

int main()
{
    int N, M, K; scanf("%d %d %d", &N, &M, &K);
    for(int i = 0, u, v, c; i < M; i++){
        scanf("%d %d %d", &u, &v, &c);
        adj[u].push_back(Edge(v, c));
    }

    priority_queue<Edge> pq;
    pq.push(Edge(1, 0));
    mind[1].push(0);

    int cur, cost, next, nc;
    while(!pq.empty()){
        cur = pq.top().to, cost = pq.top().cost; pq.pop();
        if(K <= cnt[cur]++) continue;

        for(int i = 0; i < adj[cur].size(); i++){
            next = adj[cur][i].to, nc = cost + adj[cur][i].cost;
            if(cnt[next] < K && mind[next].size() == K){
                if(nc < mind[next].top()) mind[next].pop();
            }
            if(mind[next].size() < K){
                mind[next].push(nc);
                pq.push(Edge(next, nc));
            }
        }
    }

    for(int i = 1; i <= N; i++)
        printf("%d\n", K <= cnt[i] ? mind[i].top() : -1);

    return 0;
}
