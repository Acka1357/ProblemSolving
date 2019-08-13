//
// Created by Acka on 2017. 8. 12..
//

#include <stdio.h>

#define MOD     1000000007

long long d[101][101][2];

int N, K, D;

int main()
{
    scanf("%d %d %d", &N, &K, &D);

    d[0][0][0] = 1;
    for(int i = 0; i <= N; i++)
        for(int j = 0; j <= N; j++)
            for(int k = 1; k <= K; k++){
                if(j + k > N) break;
                if(k >= D) d[i + 1][j + k][1] += d[i][j][0];
                else d[i + 1][j + k][0] += d[i][j][0];
                d[i + 1][j + k][1] += d[i][j][1];
                d[i + 1][j + k][0] %= MOD;
                d[i + 1][j + k][1] %= MOD;
            }

    long long ans = 0;
    for(int i = 1; i <= N; i++)
        ans = (ans + d[i][N][1]) % MOD;

    printf("%lld\n", ans);
    return 0;
}
