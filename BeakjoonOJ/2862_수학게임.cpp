//
// Created by Acka on 2017. 10. 11..
//

#include <stdio.h>

long long f[100] = {1, 1, };

int main()
{
    long long N; scanf("%lld", &N);

    int fcnt = 2;
    while(f[fcnt - 1] <= N){
        f[fcnt] = f[fcnt - 1] + f[fcnt - 2];
        fcnt++;
    }

    long long ans = 0;
    for(int i = fcnt - 2; i >= 0; i--)
        if(N - f[i] >= 0){
            ans = f[i];
            N -= f[i];
        }

    printf("%lld\n", ans);
    return 0;
}

