//
// Created by Acka on 10/28/16.
//

#include <stdio.h>
#include <memory.h>
#include <vector>
using namespace std;

struct Edge{
    int to, cost;
    Edge(){} Edge(int t, int c):to(t), cost(c){};
};

int N, anc[20000][16], in[20000], out[20000], t;
vector<Edge> adj[20000];
int rootd[20000];

void set_rootd(int cur, int par, int d){
    anc[cur][0] = par;
    for(int i = 1, p = par; anc[cur][i - 1]; p = anc[cur][i++])
        anc[cur][i] = anc[p][i - 1];

    in[cur] = t++;
    rootd[cur] = d;
    for(int i = 0; i < adj[cur].size(); i++)
        if(adj[cur][i].to != par)
            set_rootd(adj[cur][i].to, cur, d + adj[cur][i].cost);
    out[cur] = t++;
}

bool is_upper(int u, int v){
    return in[u] <= in[v] && out[v] <= out[u];
}

int get_lca(int u, int v){
    if(is_upper(u, v)) return u;
    if(is_upper(v, u)) return v;

    for (int i = 15; 0 <= i; i--)
        if (!is_upper(anc[u][i], v))
            u = anc[u][i];

    return anc[u][0];
}

int par[20000], qry[200000][2];

int find(int x){
    return x == par[x] ? x : par[x] = find(par[x]);
}

void link(int x, int y){
    par[find(x)] = find(y);
}

int absx(int x){
    return x < 0 ? -x : x;
}

int main()
{
    int tc; for(scanf("%d", &tc); tc--;){
        scanf("%d", &N);

        for(int i = 0; i < N; i++){
            par[i] = i;
            adj[i].clear();
            memset(anc[i], 0, sizeof(anc[i]));
        }

        char cmd;
        int a, b, idx = 0, len;
        while(scanf(" %c", &cmd) == 1){
            if(cmd == 'I'){
                scanf("%d %d", &a, &b);
                link(a - 1, b - 1);
                adj[a - 1].push_back(Edge(b - 1, len = (absx(a - b) % 1000)));
                adj[b - 1].push_back(Edge(a - 1, len));
            }
            else if(cmd == 'E'){
                scanf("%d", &a);
                qry[idx][0] = a - 1;
                qry[idx][1] = find(a - 1);
                idx++;
            }
            else break;
        }

        t = 0;
        set_rootd(0, 0, 0);
        for(int i = 0; i < idx; i++)
            printf("%d\n", rootd[qry[i][0]] + rootd[qry[i][1]] - 2 * rootd[get_lca(qry[i][0], qry[i][1])]);
    }
    return 0;
}
