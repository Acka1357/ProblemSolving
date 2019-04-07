//
// Created by Acka on 2017. 8. 17..
//

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge2{
    int u, v, cost;
    bool used;
    bool operator <(const Edge2 &A)const{
        return cost < A.cost;
    }
};

Edge2 edges[200000];
int p[50001];

int find(int x){
    return x == p[x] ? x : (p[x] = find(p[x]));
}

struct Edge{
    int to, cost;
    Edge(int t, int c):to(t), cost(c){}
};

int anc[50001][18], in[50001], out[50001], t, maxc[50001][18], maxc2[50001][18];
vector<Edge> adj[50001];

int max2(int a1, int a2, int b1, int b2){
    if(b1 < a1) return a2 == b1 ? a2 : (a2 > b1 ? a2 : b1);
    else if(b1 == a1) return a2 > b2 ? a2 : b2;
    return b2 == a1 ? b2 : (b2 > a1 ? b2 : a1);
}

void set_btm_maxc(int cur, int par){
    anc[cur][0] = par;
    for (int i = 1, p = par; anc[cur][i - 1]; p = anc[cur][i++]){
        anc[cur][i] = anc[p][i - 1];
        maxc[cur][i] = max(maxc[cur][i - 1], maxc[p][i - 1]);
        maxc2[cur][i] = max2(maxc[cur][i - 1], maxc2[cur][i - 1], maxc[p][i - 1], maxc2[p][i - 1]);
    }
    in[cur] = t++;
    for (int i = 0; i < adj[cur].size(); i++)
        if (adj[cur][i].to != par){
            maxc[adj[cur][i].to][0] = adj[cur][i].cost;
            maxc2[adj[cur][i].to][1] = 0;
            set_btm_maxc(adj[cur][i].to, cur);
        }
    out[cur] = t++;
}

int get_lca(int u, int v){
    if (in[u] <= in[v] && out[v] <= out[u]) return u;
    if (in[v] <= in[u] && out[u] <= out[v]) return v;
    for (int i = 17; 0 <= i; i--)
        if (anc[u][i] && (in[v] < in[anc[u][i]] || out[anc[u][i]] < out[v]))
            u = anc[u][i];
    return anc[u][0];
}

int get_max(int u, int a){
    int ret = 0;
    for(int i = 17; 0 <= i; i--)
        if(anc[u][i] && (in[a] <= in[anc[u][i]]  && out[anc[u][i]] <= out[a])){
            ret = max(ret, maxc[u][i]);
            u = anc[u][i];
        }
    return ret;
}

int get_max2(int u, int a){
    int ret1 = 0, ret2 = 0;
    for(int i = 17; 0 <= i; i--)
        if(anc[u][i] && (in[a] <= in[anc[u][i]]  && out[anc[u][i]] <= out[a])){
            ret1 = max(ret1, maxc[u][i]);
            ret2 = max2(ret1, ret2, maxc[u][i], maxc2[u][i]);
            u = anc[u][i];
        }
    return ret2;
}

int main()
{
    int V, E; scanf("%d %d", &V, &E);
    for(int i = 0; i < E; i++)
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].cost);

    sort(edges, edges + E);

    for(int i = 1; i <= V; i++)
        p[i] = i;

    int pcnt = 1, pu, pv, org = 0, ans = -1;
    for(int i = 0; i < E && pcnt < V; i++){
        pu = find(edges[i].u), pv = find(edges[i].v);
        if(pu != pv){
            p[pu] = pv; pcnt++;
            edges[i].used = true;
            org += edges[i].cost;
            adj[edges[i].u].push_back(Edge(edges[i].v, edges[i].cost));
            adj[edges[i].v].push_back(Edge(edges[i].u, edges[i].cost));
        }
    }

    if(pcnt < V) return 0 & printf("-1\n");

    set_btm_maxc(1, 0);

    int lca, maxu, maxv, maxu2, maxv2, rmc;
    for(int i = 0; i < E; i++){
        if(edges[i].used) continue;
        lca = get_lca(edges[i].u, edges[i].v);
        maxu = get_max(edges[i].u, lca);
        maxv = get_max(edges[i].v, lca);
        rmc = max(maxu, maxv);
        if(rmc < edges[i].cost){
            if(ans < 0) ans = org - rmc + edges[i].cost;
            else ans = min(ans, org - rmc + edges[i].cost);
            continue;
        }

        maxu2 = get_max2(edges[i].u, lca);
        maxv2 = get_max2(edges[i].v, lca);
        rmc = max2(maxu, maxu2, maxv, maxv2);
        if(rmc < edges[i].cost){
            if(ans < 0) ans = org - rmc + edges[i].cost;
            else ans = min(ans, org - rmc + edges[i].cost);
        }
    }

    printf("%d\n", ans);
    return 0;
}

