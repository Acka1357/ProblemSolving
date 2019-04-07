//
// Created by Acka on 2017. 7. 28..
//

#include <stdio.h>
#include <queue>
using namespace std;

bool chk[100001];
int to[100001], ans[100001], ind[100001];

int main()
{
    int M, N; scanf("%d %d", &M, &N);
    for(int i = 1; i <= M; i++){
        scanf("%d", &to[i]);
        to[i] += M;
        ans[i] = 1;
    }
    for(int i = 1; i <= N; i++)
        scanf("%d", &to[M + i]);

    int NN = N + M;
    for(int i = 1; i <= NN; i++)
        ind[to[i]]++;

    queue<int> q;
    for(int i = 1; i <= NN; i++)
        if(!ind[i]) q.push(i);

    while(!q.empty()){
        int cur = q.front(); q.pop();
        ans[cur] = 1;
        if(chk[to[cur]]) continue;
        chk[to[cur]] = true;
        ans[to[cur]] = 0;
        if(!(--ind[to[to[cur]]])){
            q.push(to[to[cur]]);
        }
    }

    for(int i = 1; i <= NN; i++){
        printf("%d", ans[i]);
        if(i == M || i == NN) printf("\n");
    }

    return 0;
}
