//
// Created by Acka on 2017. 1. 12..
//

#include <stdio.h>

int cnt[4];
char s[100001];

int main()
{
    int idx[256];
    idx['E'] = 0, idx['S'] = 1, idx['W'] = 2, idx['N'] = 3;

    int N, sx, sy, ex, ey;
    scanf("%d %d %d %d %d %s", &N, &sx, &sy, &ex, &ey, s);
    if(sx == ex && sy == ey) return printf("0\n");

    int need[4] = {0,};
    if(sx < ex) need[0] = ex - sx;
    else need[2] = sx - ex;
    if(sy < ey) need[3] = ey - sy;
    else need[1] = sy - ey;

    int ans = -1;
    for(int i = 0; i < N; i++){
        cnt[idx[s[i]]]++;

        bool chk = true;
        for(int j = 0; j < 4; j++)
            if(cnt[j] < need[j]) chk = false;

        if(chk){
            ans = i + 1;
            break;
        }
    }

    printf("%d\n", ans);
    return 0;
}
