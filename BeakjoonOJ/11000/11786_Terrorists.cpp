//
// Created by Acka on 7/19/16.
//

#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

struct MEdge{
    int u, v, c, ui, vi; bool use;
    MEdge(){} MEdge(int u, int v, int c, int ui, int vi):u(u), v(v), c(c), ui(ui), vi(vi){}
};

struct Edge{
    int v, c; bool use;
    Edge(){} Edge(int v, int c, bool u):v(v), c(c), use(u){}
};

struct LCA{
    int n, cnt, near_n, list_len;
    vector<vector<Edge> > G;
    vector<int> tree, node_lv, front_idx, root_dis;

    LCA(){}
    LCA(vector<vector<Edge> > &g, int n) :G(G), n(n), cnt(0), near_n(1), list_len(2 * n - 1){
        while (near_n < list_len) near_n *= 2;
        tree = vector<int>(near_n * 2);
        node_lv.resize(n + 1); front_idx.resize(n + 1); root_dis.resize(n + 1);
        set_list(1, 0, 1, 0); set_tree(near_n);
    }

    void set_list(int cur, int past, int lv, int dis){
        node_lv[cur] = lv; root_dis[cur] = dis; front_idx[cur] = cnt;
        tree[near_n + cnt++] = cur;

        int size = G[cur].size();
        for (int i = 0; i < size; i++){
            if (G[cur][i].v == past) continue;

            set_list(G[cur][i].v, cur, lv + 1, dis + G[cur][i].c);
            tree[near_n + cnt++] = cur;
        }
    }

    void set_tree(int near_n){
        for (int pow2 = near_n >> 1; pow2 > 0; pow2 >>= 1)
            for (int i = 0; i < pow2; i++){
                int idx = pow2 + i;
                if (node_lv[tree[idx * 2]] < node_lv[tree[idx * 2 + 1]])
                    tree[idx] = tree[idx * 2];
                else tree[idx] = tree[idx * 2 + 1];
            }
    }

    int query(int ql, int qr, int l, int r, int idx){
        if (ql <= l && r <= qr) return tree[idx];

        int lca1 = -1, lca2 = -1, half = (l + r) / 2;
        if(ql <= half) lca1 = query(ql, qr, l, half, idx * 2);
        if(half < qr) lca2 = query(ql, qr, half + 1, r, idx * 2 + 1);

        if (lca1 < 0) return lca2; if (lca2 < 0) return lca1;
        return node_lv[lca1] < node_lv[lca2] ? lca1 : lca2;
    }

    int get_lca(int node1, int node2){
        if (front_idx[node1] > front_idx[node2]) swap(node1, node2);
        return query(front_idx[node1], front_idx[node2], 0, near_n - 1, 1);
    }

    int get_distance(int node1, int node2){
        return root_dis[node1] + root_dis[node2] - 2 * root_dis[get_lca(node1, node2)];
    }
};

MEdge edge[100051];
int par[100051];

int find(int x){
    return x == par[x] ? x : par[x] = find(par[x]);
}

void link(int x, int y){
    par[find(y)] = find(x);
}

int main()
{
    int tc, st = 0; for(scanf("%d", &tc); st++ < tc;){
        int N, M, Q; scanf("%d %d %d", &N, &M, &Q);

        vector<vector<Edge> > adj(N + 1);
        for(int i = 0, u, v, c; i < M; i++) {
            scanf("%d %d %d", &u, &v, &c);
            edge[i] = MEdge(u, v, c, adj[u].size(), adj[v].size());
            adj[u].push_back(Edge(v, c, false));
            adj[v].push_back(Edge(u, c, false));
        }

        vector<MEdge> unused;
        for(int i = 1; i <= N; i++) par[i] = i;
        for(int i = 0, cov = 1; i < M; i++){
            int u = edge[i].u, v = edge[i].v, pu = find(u), pv = find(v);
            if(pu != pv){
                link(pu, pv);
                adj[u][idx[i][0]].use = adj[v][idx[i][1]].use = true;
            }
            else unused.push_back(edge[i]);
        }


        int tcnt = 0;
        LCA lca[201];

        printf("Case %d:\n", st);
        while(Q--){
            int u, v; scanf("%d %d", &u, &v);
            int ans = lca[0].get_distance(u, v);
            for(int i = 0; i < tcnt; i++)
                ans = min(ans, lca[i].get_distance(u, v));
            printf("%d\n", ans);
        }
    }
    return 0;
}

