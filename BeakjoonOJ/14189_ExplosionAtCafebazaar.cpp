//
// Created by Acka on 2017. 9. 4..
//

#include <stdio.h>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;

bool chk[50001], d[50001][2];
int N, M, idx[50001], low[50001], seq[50001], gn[50001], top, cnt, gcnt;
int vchk[50001], gscr[50001], rgin[50001];
vector<int> adj[50001], g[50001], radj[50001];

void init(int N){
    memset(chk, false, (N + 1) * sizeof(chk[0]));
    memset(d, false, (N + 1) * sizeof(d[0]));
    memset(idx, 0, (N + 1) * sizeof(idx[0]));
    memset(low, 0, (N + 1) * sizeof(low[0]));
    memset(vchk, 0, (N + 1) * sizeof(vchk[0]));
    memset(gscr, 0, (N + 1) * sizeof(gscr[0]));
    memset(rgin, 0, (N + 1) * sizeof(rgin[0]));

    top = cnt = gcnt = 0;
    for(int i = 1; i <= N; i++){
        adj[i].clear();
        g[i].clear();
        radj[i].clear();
    }
}

int dfs(int cur){
    idx[cur] = low[cur] = ++cnt;
    seq[++top] = cur;

    chk[cur] = true;
    for(int i = 0; i < adj[cur].size(); i++){
        int next = adj[cur][i];
        if(!idx[next]) low[cur] = min(low[cur], dfs(next));
        else if(chk[next]) low[cur] = min(low[cur], idx[next]);
    }

    if(idx[cur] == low[cur]){
        gcnt++;
        while(seq[top] != cur){
            g[gcnt].push_back(seq[top]);
            gn[seq[top]] = gcnt;
            chk[seq[top--]] = false;
        }
        g[gcnt].push_back(cur);
        gn[seq[top--]] = gcnt;
        chk[cur] = false;
    }
    return low[cur];
}

int main()
{
    while(scanf("%d %d", &N, &M) == 2){
        if(N + M == 0) break;

        init(N);
        for(int i = 0, u, v; i < M; i++){
            scanf("%d %d", &u, &v);
            adj[u].push_back(v);
        }

        for(int i = 1; i <= N; i++)
            if(!idx[i]) dfs(i);

        for(int i = 1; i <= gcnt; i++)
            for(int j = 0; j < g[i].size(); j++){
                int cur = g[i][j];
                for(int k = 0; k < adj[cur].size(); k++){
                    if(gn[adj[cur][k]] == i){
                        gscr[i] = max(gscr[i], 1);
                        if(vchk[adj[cur][k]] == i) gscr[i] = 2;
                        else vchk[adj[cur][k]] = i;
                    }
                    else{
                        radj[gn[adj[cur][k]]].push_back(i);
                        rgin[i]++;
                    }
                }
            }

        queue<int> q;
        for(int i = 1; i <= gcnt; i++)
            if(rgin[i] == 0)
                q.push(i);

        int cur, next;
        while(!q.empty()){
            cur = q.front(); q.pop();
            d[cur][0] |= (gscr[cur] == 1);
            d[cur][1] |= (gscr[cur] == 2);
            for(int i = 0; i < radj[cur].size(); i++) {
                next = radj[cur][i];
                d[next][0] |= d[cur][0] | (gscr[next] == 1);
                d[next][1] |= d[cur][1] | (d[cur][0] && gscr[next] == 1) | (gscr[next] == 2);
                if(--rgin[next] == 0) q.push(next);
            }
        }

        int ans = 0;
        for(int i = 1; i <= gcnt; i++)
            if(d[i][1]) ans += g[i].size();
        printf("%d\n", ans);
    }
    return 0;
}

