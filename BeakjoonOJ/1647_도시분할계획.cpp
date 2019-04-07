//
// Created by Acka on 2017. 8. 29..
//

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge{
    int u, v, cost;
    bool operator <(const Edge &A)const{
        return cost < A.cost;
    }
};

Edge edge[1000000];
int par[100001];

int find(int x){
    return x == par[x] ? x : (par[x] = find(par[x]));
}

void link(int px, int py){
    par[py] = px;
}

int main()
{
    int N, M; scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++)
        scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].cost);

    sort(edge, edge + M);
    for(int i = 1; i <= N; i++)
        par[i] = i;

    int cnt = 2, sum = 0, pu, pv;
    for(int i = 0; i < M && cnt < N; i++){
        pu = find(edge[i].u), pv = find(edge[i].v);
        if(pv != pu){
            sum += edge[i].cost;
            cnt++;
        }
    }

    printf("%d\n", sum);
    return 0;
}
