//
// Created by Acka on 2017. 8. 13..
//

#include <stdio.h>
#include <memory.h>
#include <algorithm>
using namespace std;

bool chk[11];
int N, map[10][10], used[10], ucnt, cur[11][10][10], ans;

void coloring(int idx, int c){
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cur[idx][i][j] = cur[idx - 1][i][j];

    int l = N, r = -1, t = N, b = -1;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            if(map[i][j] == c){
                l = min(l, j); r = max(r, j);
                t = min(t, i); b = max(t, i);
            }

    for(int i = t; i <= b; i++)
        for(int j = l; j <= r; j++)
            cur[idx][i][j] = c;
}

bool dfs(int idx){
    if(idx == ucnt){
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                if(map[i][j] != cur[idx][i][j])
                    return false;
        return true;
    }

    for(int i = 0; i < ucnt; i++)
        if(!chk[i]){
            chk[i] = true;
            coloring(idx + 1, used[i]);
            if(dfs(idx + 1)){
                chk[i] = false;
                if(idx == 0){
                    ans++;
                    continue;
                }
                return true;
            }
            chk[i] = false;
        }
}

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            scanf("%1d", &map[i][j]);

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            if(!chk[map[i][j]] && map[i][j] != 0){
                chk[map[i][j]] = true;
                used[ucnt++] = map[i][j];
            }

    memset(chk, false, sizeof(chk));
    dfs(0);

    printf("%d\n", ans);
    return 0;
}
