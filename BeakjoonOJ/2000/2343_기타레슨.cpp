//
// Created by Acka on 2017. 11. 8..
//

#include <stdio.h>

int len[100000], maxl;

int main()
{
    int N, M; scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++){
        scanf("%d", &len[i]);
        if(maxl < len[i]) maxl = len[i];
    }

    int l = maxl, r = 1000000000, m, ans;
    while(l <= r){
        m = (l + r) / 2;

        int cur = 0, cnt = 1;
        for(int i = 0; i < N; i++){
            cur += len[i];
            if(cur > m){
                cur = len[i];
                cnt++;
            }
        }
        if(cnt <= M) r = m - 1, ans = m;
        else l = m + 1;
    }

    printf("%d\n", ans);
    return 0;
}
