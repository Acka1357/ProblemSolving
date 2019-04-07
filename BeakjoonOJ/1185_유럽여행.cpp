//
// Created by Acka on 9/30/16.
//

#include <stdio.h>
#include <algorithm>
using namespace std;

struct Edge{
    int u, v, c;
    bool operator <(const Edge &A)const{
        return c < A.c;
    }
};

int cost[10001], p[10001], pn[10001];
Edge edge[100000];

int find(int x){
    return p[x] == x ? x : find(p[x]);
}

void link(int px, int py){
    p[py] = px;
    pn[px] += pn[py];
}

int main()
{
    int N, M; scanf("%d %d", &N, &M);

    int ans = 1 << 30;
    for(int i = 1; i <= N; i++){
        scanf("%d", &cost[i]);
        ans = min(ans, cost[i]);
    }

    for(int i = 0; i < M; i++){
        scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].c);
        edge[i].c <<= 1; edge[i].c += cost[edge[i].u] + cost[edge[i].v];
    }

    sort(edge, edge + M);

    for(int i = 1; i <= N; i++) {
        p[i] = i;
        pn[i] = 1;
    }

    for(int i = 0, cnt = 1; cnt < N; i++){
        int pu = find(edge[i].u), pv = find(edge[i].v);
        if(pu != pv) {
            if (pn[pu] < pn[pv]) link(pv, pu);
            else link(pu, pv);
            ans += edge[i].c;
            cnt++;
        }
    }

    printf("%d\n", ans);
    return 0;
}
