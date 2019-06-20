//
// Created by Acka on 2017. 5. 13..
//

#include <stdio.h>

#define MOD     1000000007

long long d[100001] = {0, 0, 1};
long long f[100001] = {1, 1, 2};

int main()
{
    int N; scanf("%d", &N);

    for(int i = 3; i <= N; i++){
        d[i] = ((i - 1) * (d[i - 1] + d[i - 2])) % MOD;
        f[i] = (i * f[i - 1]) % MOD;
    }

    printf("%lld\n", (d[N] * f[N]) % MOD);
    return 0;
}

