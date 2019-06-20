//
// Created by Acka on 11/9/16.
//

#include <stdio.h>

int main()
{
    int N, K; scanf("%d %d", &N, &K);

    int ans = 0, l = 1, r = 1000000001, m;
    while(l <= r){
        m = (l + r) / 2;

        int sum = 0, add;
        for(long long int i = 1; i <= N; i++) {
            add = m / i;
            sum += (N <= add ? N : add);
        }

        if(K <= sum){
            ans = m;
            r = m - 1;
        }
        else l = m + 1;
    }

    printf("%d\n", ans);
    return 0;
}