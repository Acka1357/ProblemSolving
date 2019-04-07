//
// Created by Acka on 2017. 8. 1..
//

#include <stdio.h>

int t[100000];

int main()
{
    int N, M; scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++)
        scanf("%d", &t[i]);

    long long l = 0, r = (long long)M * t[0], m, ans, sum;
    while(l <= r){
        m = (l + r) / 2;

        for(int i = sum = 0; i < N; i++)
            sum += m / t[i];

        if(sum >= M){
            ans = m;
            r = m - 1;
        }
        else l = m + 1;
    }

    printf("%lld\n", ans);
    return 0;
}

