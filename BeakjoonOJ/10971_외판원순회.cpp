//
// Created by Acka on 2017. 2. 5..
//

#include <stdio.h>
#include <algorithm>
using namespace std;

bool chk[10];
int N, w[10][10], ans = 20000000;

void dfs(int cur, int cnt, int cost){
    if(N == cnt){
        if(w[cur][0]) ans = min(ans, cost + w[cur][0]);
        return ;
    }

    for(int i = 0; i < N; i++)
        if(!chk[i] && w[cur][i]){
            chk[i] = true;
            dfs(i, cnt + 1, cost + w[cur][i]);
            chk[i] = false;
        }
}

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            scanf("%d", &w[i][j]);

    chk[0] = true;
    dfs(0, 1, 0);

    printf("%d\n", ans);
    return 0;
}
