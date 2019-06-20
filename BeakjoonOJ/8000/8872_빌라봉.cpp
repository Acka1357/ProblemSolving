//
// Created by Acka on 2017. 11. 16..
//

#include <stdio.h>
#include <vector>
using namespace std;

struct Edge{
    int to, cost;
    Edge(int t, int c):to(t), cost(c){}
};

vector<Edge> adj[100000];
bool chk[100000];
int ci[100000], max1, max2, root, maxl;

int max_r(int p){
    chk[p] = true;
    int l1 = 0, l2 = 0, l;
    for(int i = 0; i < adj[p].size(); i++)
        if(!chk[adj[p][i].to]){
            l = max_r(adj[p][i].to) + adj[p][i].cost;
            if(l > l1){
                l2 = l1; l1 = l; ci[p] = i;
            }
            else if(l > l2) l2 = l;
        }

    if(l1 + l2 > maxl){
        maxl = l1 + l2, root = p;
        max1 = l1, max2 = l2;
    }
    return l1;
}

int calc_rad(int cent){
    int rad = max(max1, max2);
    while(max1 > max2){
        max1 -= adj[cent][ci[cent]].cost;
        max2 += adj[cent][ci[cent]].cost;
        cent = adj[cent][ci[cent]].to;
        rad = min(rad, max(max1, max2));
    }
    return rad;
}

int main()
{
    int N, M, L; scanf("%d %d %d", &N, &M, &L);
    for(int i = 0, u, v, c; i < M; i++){
        scanf("%d %d %d", &u, &v, &c);
        adj[u].push_back(Edge(v, c));
        adj[v].push_back(Edge(u, c));
    }

    int ans = 0, d1 = 0, d2 = 0, d3 = 0, rad;
    for(int i = 0; i < N; i++){
        if(chk[i]) continue;
        maxl = max1 = max2 = 0;
        max_r(i);
        rad = calc_rad(root);
        ans = max(ans, maxl);
        if(rad > d1){ d3 = d2; d2 = d1; d1 = rad; }
        else if(rad > d2){ d3 = d2; d2 = rad; }
        else if(rad > d3) d3 = rad;
    }

    if(M < N - 1) ans = max(ans, d1 + d2 + L);
    if(M < N - 2) ans = max(ans, d2 + d3 + 2 * L);
    printf("%d\n", ans);
    return 0;
}
