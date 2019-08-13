//
// Created by Acka on 8/29/16.
//

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <stack>
using namespace std;

#define MOD 1000000007

int cnt, gcnt, gg[200001];
vector<int> chk, order;
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

long long int pow2[200001] = {1, 2, 4,};

int main()
{
    int N; scanf("%d", &N);

    adj.resize(N + 1);
    radj.resize(N + 1);
    chk.resize(N + 1);
    order.resize(N);
    for(int i = 1, x; i <= N; i++){
        scanf("%d", &x);
        adj[i].push_back(x);
        radj[x].push_back(i);
    }

    for(int i = 1; i <= N; i++)
        if(!chk[i]) dfs(i);

    for(int i = N - 1; 0 <= i; i--)
        if (chk[order[i]] < 0) {
            ++gcnt;
            rdfs(order[i]);
        }

    for(int i = 1; i <= N; i++)
        gg[chk[i]]++;

    for(int i = 2; i <= N; i++)
        pow2[i] = (pow2[i - 1] << 1) % MOD;

    long long int ans = 1;
    long long int sum1 = 0;
    for(int i = 1; i <= gcnt; i++){
        if(gg[i] == 1) sum1++;
        else{
            int x = (pow2[gg[i]] < 2 ? (pow2[gg[i]] + MOD) : pow2[gg[i]]) - 2;
            ans = (ans * x) % MOD;
        }
    }

    ans = (ans * pow2[sum1]) % MOD;
    printf("%lld\n", ans);
    return 0;
}

