//
// Created by Acka on 7/30/16.
//

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> adj[10001], rev[10001], comp[10001], scc[10001], nb;
bool chk[10001];
int N, M, S, T, idx, cn[10001], linked[10001], d[10001];

void dfs(int cur){
    chk[cur] = true;
    for(int i = 0; i < adj[cur].size(); i++)
        if(!chk[adj[cur][i]]) dfs(adj[cur][i]);
    nb.push_back(cur);
}

void rdfs(int cur){
    cn[cur] = idx;
    for(int i = 0; i < rev[cur].size(); i++)
        if(!cn[rev[cur][i]]) rdfs(rev[cur][i]);
    comp[idx].push_back(cur);
}

int get_dist(int cur){
    if(cur == cn[S]) return comp[cn[S]].size();
    if(d[cur] || !scc[cur].size()) return d[cur];

    for(int i = 0; i < scc[cur].size(); i++)
        d[cur] = max(d[cur], get_dist(scc[cur][i]));

    return d[cur] = d[cur] + (d[cur] ? comp[cur].size() : 0);
}

int main()
{
    scanf("%d %d %d %d", &N, &M, &S, &T);
    for(int i = 0, u, v; i < M; i++){
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        rev[v].push_back(u);
    }

    for(int i = 1; i <= N; i++)
        if(!chk[i]) dfs(i);

    for(; !nb.empty(); nb.pop_back())
        if(!cn[nb.back()]){
            ++idx;
            rdfs(nb.back());
        }

    for(int i = 1, cur; i <= idx; i++) {
        linked[i] = i;
        for (int j = 0; j < comp[i].size(); j++)
            for (int k = 0; k < rev[(cur = comp[i][j])].size(); k++)
                if (linked[cn[rev[cur][k]]] != i) {
                    linked[cn[rev[cur][k]]] = i;
                    scc[i].push_back(cn[rev[cur][k]]);
                }
    }

    printf("%d\n", get_dist(cn[T]));
    return 0;
}
