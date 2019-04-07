//
// Created by Acka on 2017. 7. 1..
//

#include <stdio.h>
#include <vector>
using namespace std;

#define BASE    20000

int neg[40001]; // neg[i] = i + N
int cnt, gcnt;
vector<int> chk, neg, order, res;
vector<int > adj[20001], radj[20001];

void dfs(int cur){
    chk[cur] = -1;
    for (int i = adj[cur].size() - 1; 0 <= i; i--)
        if (!chk[adj[cur][i]]) dfs(adj[cur][i]);
    order[cnt++] = cur;
}

void rdfs(int cur){
    chk[cur] = gcnt;
    for (int i = radj[cur].size() - 1; 0 <= i; i--)
        if (chk[radj[cur][i]] < 0)
            rdfs(radj[cur][i]);
}


int main()
{
    for(int i = 0; i < BASE; i++){
        neg[i] = i + BASE;
        neg[i + BASE] = i;
    }

    int T, tc = 0; for(scanf("%d ", &T); tc++ < T;){
        int N, M; scanf("%d %d", &N, &M);

        int x, a, b, rown, coln;
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++){
                scanf("%d %d %d", &x, &a, &b);
                rown = i * 100 + a;
                coln = 10000 + j * 100 + b;
                if(x){
                    adj[rown].push_back(coln);
                    adj[coln].push_back(rown);
                    radj[neg]
                }
            }
        for (int i = 1; i <= V; i++)
            if (!chk[i]) dfs(i);

        for (int i = V - 1, cur; 0 <= i; i--){
            if (chk[cur = order[i]] < 0) {
                ++gcnt;
                rdfs(cur);
            }

            if (chk[neg[cur]] == chk[cur]) return printf("0\n");
            res[cur <= N ? cur : cur - N] = (cur <= N);

        printf("Case #%d\n%d\n", tc, ans - (ans & 1));
    }
    return 0;
}
