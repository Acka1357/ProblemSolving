//
// Created by Acka on 2017. 7. 13..
//

//http://ideone.com/J3CVpI      smu's tarjan

#include <stdio.h>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
using namespace std;

bool chk[500001];
int idx[500001], low[500001], sn[500001], cnt, scnt;
vector<int> adj[500001], memb[500001];
stack<int> seq;

int dfs(int cur){
    idx[cur] = low[cur] = ++cnt;
    seq.push(cur);

    chk[cur] = true;
    for(int i = 0; i < adj[cur].size(); i++){
        int next = adj[cur][i];
        if(!idx[next]) low[cur] = min(low[cur], dfs(next));
        else if(chk[next]) low[cur] = min(low[cur], idx[next]);
    }

    if(idx[cur] == low[cur]){
        ++scnt;
        while(seq.top() != cur){
            memb[scnt].push_back(seq.top());
            chk[seq.top()] = false;
            sn[seq.top()] = scnt;
            seq.pop();
        }
        memb[scnt].push_back(cur);
        chk[cur] = false;
        sn[seq.top()] = scnt;
        seq.pop();
    }
    return low[cur];
}

vector<int> sadj[500001];
int mon[500001], smon[500001], linked[500001], sind[500001], sum[500001];
bool res[500001], sres[500001];

int main()
{
    int N, M; scanf("%d %d", &N, &M);
    for(int i = 0, u, v; i < M; i++){
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
    }

    for(int i = 1; i <= N; i++)
        scanf("%d", &mon[i]);

    int S, P; scanf("%d %d", &S, &P);
    for(int i = 0, x; i < P; i++){
        scanf("%d", &x);
        res[x] = true;
    }

    for(int i = 1; i <= N; i++)
        if(!idx[i]) dfs(i);

    for(int i = 1; i <= scnt; i++)
        for(int j = 0; j < memb[i].size(); j++){
            int& mem = memb[i][j];
            sres[i] |= res[mem];
            smon[i] += mon[mem];
            linked[i] = i;
            for(int k = 0; k < adj[mem].size(); k++)
                if(linked[sn[adj[mem][k]]] != i){
                    linked[sn[adj[mem][k]]] = i;
                    sind[sn[adj[mem][k]]]++;
                    sadj[i].push_back(sn[adj[mem][k]]);
                }
        }

    queue<int> q;
    sum[sn[S]] = smon[sn[S]];
    for(int i = 1; i <= scnt; i++)
        if(!sind[i]) q.push(i);

    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(int i = 0; i < sadj[cur].size(); i++){
            int& to = sadj[cur][i];
            if(!(--sind[to])) q.push(to);
            if(sum[cur]) sum[to] = max(sum[to], sum[cur] + smon[to]);
        }
    }

    int ans = 0;
    for(int i = 1; i <= scnt; i++)
        if(sres[i]) ans = max(ans, sum[i]);

    printf("%d\n", ans);
    return 0;
}

