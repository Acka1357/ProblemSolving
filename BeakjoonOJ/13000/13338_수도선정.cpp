//
// Created by Acka on 10/17/16.
//

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int cnt, gcnt, chk[50];
vector<int> adj[50], order, gn;

void dfs(int cur){
    order[cnt++] = cur;
    chk[cur] = 1;
    for(int i = 0; i < adj[cur].size(); i++)
        if(!chk[adj[cur][i]]) dfs(adj[cur][i]);
}

void rdfs(int cur){
    gn[cur] = gcnt;
    chk[cur] = 1;
    for(int i = 0; i < adj[cur].size(); i++)
        if(!chk[adj[cur][i]]) rdfs(adj[cur][i]);
}

int main()
{
    int N; scanf("%d", &N);
    for(int i = 0, v; i < N; i++){
        scanf("%d", &v);
        adj[i].push_back(v);
        adj[v].push_back(i);
    }

    int ans = N - 1;
    for(int i = 0; i < N; i++)
        ans = min(ans, N - (int)adj[i].size());

    printf("%d\n", ans);
    return 0;
}
