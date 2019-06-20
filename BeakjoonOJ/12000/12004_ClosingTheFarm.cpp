//
// Created by Acka on 2016. 12. 10..
//

#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;

vector<int> adj[30001];
int q[30001], par[30001], ans[30000];

int find(int x){
    return x == par[x] ? x : par[x] = find(par[x]);
}

bool link(int x, int y){
    int px = find(x), py = find(y);
    if(px == py) return false;
    if(rand() & 1) par[px] = py;
    else par[py] = px;
    return true;
}

int main()
{
    srand(time(NULL));

    int N, M; scanf("%d %d", &N, &M);
    for(int i = 0, u, v; i < M; i++){
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 0; i < N; i++)
        scanf("%d", &q[i]);

    int pcnt = 0;
    for(int i = N - 1; 0 <= i; i--){
        int& cur = q[i];
        par[cur] = cur; pcnt++;

        for(int j = 0; j < adj[cur].size(); j++) {
            if(!par[adj[cur][j]]) continue;
            if(link(cur, adj[cur][j])) pcnt--;
        }

        if(pcnt == 1) ans[i] = 1;
    }

    for(int i = 0; i < N; i++)
        printf("%s\n", ans[i] ? "YES" : "NO");

    return 0;
}

