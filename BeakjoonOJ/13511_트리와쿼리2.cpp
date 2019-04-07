//
// Created by Acka on 2017. 8. 17..
//

#include <stdio.h>
#include <vector>
using namespace std;

struct Edge{
    int to, cost;
    Edge(int t, int c):to(t), cost(c){}
};

int N, anc[100001][19], in[100001], out[100001], t;
vector<Edge> adj[100001];
long long rootd[100001];

void set_rootd(int cur, int par, long long d){
    anc[cur][0] = par;
    for (int i = 1, p = par; anc[cur][i - 1]; p = anc[cur][i++])
        anc[cur][i] = anc[p][i - 1];
    in[cur] = t++;
    rootd[cur] = d;
    for (int i = 0; i < adj[cur].size(); i++)
        if (adj[cur][i].to != par)
            set_rootd(adj[cur][i].to, cur, d + adj[cur][i].cost);
    out[cur] = t++;
}

int get_lca(int u, int v){
    if (in[u] <= in[v] && out[v] <= out[u]) return u;
    if (in[v] <= in[u] && out[u] <= out[v]) return v;
    for (int i = 18; 0 <= i; i--)
        if (anc[u][i] && (in[v] < in[anc[u][i]] || out[anc[u][i]] < out[v]))
            u = anc[u][i];
    return anc[u][0];
}

int calc_depth(int u, int a){
    int d = 0;
    for(int i = 18, b = (1 << 18); 0 <= i; i--, b >>= 1)
        if(anc[u][i] && (in[a] <= in[anc[u][i]] || out[anc[u][i]] <= out[a])){
            u = anc[u][i];
            d += b;
        }
    return d;
}

int get_kth(int u, int k){
    for(int i = 0; k; i++, k >>= 1)
        if(k & 1) u = anc[u][i];
    return u;
}

int main()
{
    int N; scanf("%d", &N);
    for(int i = 1, u, v, w; i < N; i++){
        scanf("%d %d %d", &u, &v, &w);
        adj[u].push_back(Edge(v, w));
        adj[v].push_back(Edge(u, w));
    }

    set_rootd(1, 0, 0);

    int M, cmd, u, v, k, lca, du;
    for(scanf("%d", &M); M--;){
        scanf("%d %d %d", &cmd, &u, &v);
        lca = get_lca(u, v);
        if(cmd == 1) printf("%lld\n", rootd[u] + rootd[v] - 2 * rootd[lca]);
        else{
            scanf("%d", &k); k--;
            du = calc_depth(u, lca);
            if(k <= du) printf("%d\n", get_kth(u, k));
            else printf("%d\n", get_kth(v, du + calc_depth(v, lca) - k));
        }
    }
    return 0;
}

