//
// Created by Acka on 2016. 12. 6..
//

#include <stdio.h>
#include <algorithm>
using namespace std;

int par[25 * 25], vcnt[25 * 25];

int find(int x){
    return par[x] == x ? x : par[x] = find(par[x]);
}

void link(int x, int y){
    int px = find(x), py = find(y);
    if(px == py) return ;
    vcnt[px] += vcnt[py];
    par[py] = px;
}

int main()
{
    int N; scanf("%d", &N);

    char map[25][26];
    for(int i = 0; i < N; i++)
        scanf("%s", map[i]);

    int idx[25][25], icnt = 0;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            if(map[i][j] == '1'){
                par[icnt] = icnt;
                vcnt[icnt] = 1;

                if(i){
                    if(map[i - 1][j] == '1') link(icnt, idx[i - 1][j]);
                }
                if(j){
                    if(map[i][j - 1] == '1') link(icnt, idx[i][j - 1]);
                }

                idx[i][j] = icnt++;
            }

    int ans[25 * 13], cnt = 0;
    for(int i = 0; i < icnt; i++)
        if(par[i] == i) ans[cnt++] = vcnt[i];

    sort(ans, ans + cnt);

    printf("%d\n", cnt);
    for(int i = 0; i < cnt; i++)
        printf("%d\n", ans[i]);

    return 0;
}
