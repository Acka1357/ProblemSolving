//
// Created by Acka on 2017. 4. 13..
//

#include <stdio.h>
#include <vector>
using namespace std;

int sparse[100001][20], in[100001], out[100001], t;
vector<int> adj[100001];

void set_order(int cur){
    in[cur] = ++t;
    for(int i = 0; i < adj[cur].size(); i++)
        if(!sparse[adj[cur][i]][0]){
            sparse[adj[cur][i]][0] = cur;
            set_order(adj[cur][i]);
        }
    out[cur] = ++t;
}

void set_sparse(int N){
    for(int j = 1; j < 20; j++)
        for(int i = 1; i <= N; i++){
            if(sparse[i][j - 1] < 0) sparse[i][j] = -1;
            else sparse[i][j] = sparse[sparse[i][j - 1]][j - 1];
        }
}

int get_lca(int u, int v){
    if(in[u] <= in[v] && out[v] <= out[u]) return u;

    for(int i = 19; 0 <= i; i--){
        if(sparse[u][i] < 0) continue;
        if(in[v] < in[sparse[u][i]] || out[sparse[u][i]] < out[v])
            u = sparse[u][i];
    }
    return sparse[u][0];
}

int main()
{
    int N; scanf("%d", &N);

    int u, v;
    for(int i = 1; i < N; i++){
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    sparse[1][0] = -1;
    set_order(1);
    set_sparse(N);

    int M; scanf("%d", &M);
    while(M--){
        scanf("%d %d", &u, &v);
        printf("%d\n", get_lca(u, v));
    }

    return 0;
}
