//
// Created by Acka on 8/8/16.
//

#include <stdio.h>
#include <vector>
using namespace std;

int N, M, V, cnt, gcnt;
vector<int> chk, neg, order, res;
vector<vector<int> > adj, radj;

void dfs(int cur){
    chk[cur] = -1;
    for(int i = adj[cur].size() - 1; 0 <= i; i--)
        if(!chk[adj[cur][i]]) dfs(adj[cur][i]);
    order[cnt++] = cur;
}

void rdfs(int cur){
    chk[cur] = gcnt;
    for(int i = radj[cur].size() - 1; 0 <= i; i--)
        if (chk[radj[cur][i]] < 0)
            rdfs(radj[cur][i]);
}

int main()
{
    scanf("%d %d", &N, &M);
    adj.resize((V = 2 * N) + 1);
    radj.resize(V + 1);
    neg.resize(V + 1);
    chk.resize(V + 1);
    order.resize(V);
    res.resize(N + 1);

    for(int i = 1; i <= N; i++) {
        neg[i] = i + N;
        neg[N + i] = i;
    }

    int nu, nv;
    for(int i = 0, u, v; i < M; i++){
        scanf("%d %d", &u, &v);

        if(0 < u) nu = u + N;
        else { nu = -u; u = nu + N; }
        if(0 < v) nv = v + N;
        else { nv = -v; v = nv + N; }

        adj[nu].push_back(v);
        adj[nv].push_back(u);
        radj[v].push_back(nu);
        radj[u].push_back(nv);
    }

    for(int i = 1; i <= V; i++)
        if(!chk[i]) dfs(i);

    for(int i = V - 1, cur; 0 <= i; i--){
        if(chk[cur = order[i]] < 0) {
            ++gcnt;
            rdfs(cur);
        }

        if(chk[neg[cur]] == chk[cur]) return printf("0\n");
        res[cur <= N ? cur : cur - N] = (cur <= N);
    }

    printf("1\n");
    for(int i = 1; i <= N; i++)
        printf("%d ", res[i]);
    printf("\n");

    return 0;
}
