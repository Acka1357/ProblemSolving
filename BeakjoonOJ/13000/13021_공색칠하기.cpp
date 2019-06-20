//
// Created by Acka on 7/15/16.
//

#include <stdio.h>

int main()
{
    int N, M; scanf("%d %d", &N, &M);

    int c[1001] = {0,};
    for(int i = 1, l, r; i <= M; i++){
        scanf("%d %d", &l, &r);
        for(int j = l; j <= r; j++)
            c[j] = i;
    }

    long long int ans = 1;
    bool chk[1001] = {0,};
    for(int i = 1; i <= N; i++)
        if(!chk[c[i]] && c[i]){
            chk[c[i]] = true;
            ans <<= 1;
        }

    printf("%lld\n", ans);
    return 0;
}

