//
// Created by Acka on 8/30/16.
//

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge{
    int v, cost;
    Edge(){}
    Edge(int v, int c):v(v), cost(c){}
};

int N, K;
int d[1001][1001][2], child_esum[1001];
vector<Edge> adj[1001];

void cut_max(int cur, int par){
    for(int i = 0; i < adj[cur].size(); i++)
        if(adj[cur][i] != par){
            cut_max(adj[cur][i].v, cur);
            child_esum[cur] += adj[cur][i].cost;
        }

    for(int i = 0, km = 0; i < adj[cur].size(); i++){
        if(adj[cur][i] == par) continue;
        for(int j = 0, next = adj[cur][i].v; j <= K; j++){
            for(int k = 0; k <)

            km += adj[next].size();
        }
    }
}

int main()
{
    scanf("%d %d", &N, &K);
    for(int i = 1, u, v, c; i < N; i++){
        scanf("%d %d %d", &u, &v, &c);
        adj[u].push_back(Edge(v, c));
        adj[v].push_back(Edge(u, c));
    }

    cut_max(1, -1);

    printf("%d\n", max(d[1][K][0], d[1][K][1]));
    return 0;
}
