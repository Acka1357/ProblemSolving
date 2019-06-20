//
// Created by Acka on 11/2/16.
//

#include <stdio.h>

#define MOD 1000000000;

long long int d[201][201];

int main()
{
    int N, K; scanf("%d %d", &N, &K);

    d[0][0] = 1;
    for(int k = 1; k <= K; k++)
        for(int i = 0; i <= N; i++) {
            for (int j = i; j <= N; j++)
                d[k][j] += d[k - 1][j - i];
            d[k][i] %= MOD;
        }

    printf("%lld\n", d[K][N]);
    return 0;
}
