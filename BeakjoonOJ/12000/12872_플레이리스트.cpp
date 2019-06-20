//
// Created by Acka on 7/5/16.
//

#include <stdio.h>

#define MOD 1000000007

long long int d[101][101];

int main()
{
    int N, M, P; scanf("%d %d %d", &N, &M, &P);

    d[0][0] = 1;
    for(int i = 1; i <= P; i++)
        for(int j = 0; j <= N; j++){
            if(j != N) d[i][j + 1] = (d[i][j + 1] + d[i - 1][j] * (N - j)) % MOD;
            if(M < j) d[i][j] = (d[i][j] + d[i - 1][j] * (j - M)) % MOD;
        }

    printf("%lld\n", d[P][N]);
    return 0;
}

