//
// Created by Acka on 10/16/16.
//

#include <stdio.h>

#define MOD 1000000007

int e[2001], d[2001], pow2[2000], comb[2000][2001];

int main()
{
    pow2[0] = e[0] = e[1] = comb[0][0] = 1;

    int N; scanf("%d", &N);
    for(int i = 1; i < N; i++)
        pow2[i] = (pow2[i - 1] << 1) % MOD;

    for(int i = 2; i <= N; i++)
        e[i] = ((long long)e[i - 1] * pow2[i - 2]) % MOD;

    for(int i = 1; i < N; i++)
        for(int j = comb[i][0] = 1; j <= i; j++)
            comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j < i; j++)
            d[i] = (d[i] + (((long long)d[j] * e[i - j]) % MOD) * comb[i - 1][j - 1]) % MOD;
        d[i] = (e[i] - d[i] + MOD) % MOD;
    }

    printf("%lld\n", ((long long)d[N] * ((N * (N - 1)) / 2 + 1)) % MOD);
    return 0;
}
