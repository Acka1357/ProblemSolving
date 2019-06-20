//
// Created by Acka on 5/7/16.
//

#include <stdio.h>
#include <algorithm>
using namespace std;

#define MOD 1000000003

long long int d[3][1000][500][2];

int main()
{
    int N, K; scanf("%d %d", &N, &K);

    d[0][0][1][1] = 1;
    d[1][0][0][0] = d[2][0][0][0] = 1;
    for(int i = 1; i < N; i++)
        for(int j = 0, jm = min((i / 2) + 1, K); j <= jm; j++)
            for(int k = 0; k < 3; k++){
                d[k][i][j][0] = (d[k][i][j][0] + d[k][i - 1][j][0] + d[k][i - 1][j][1]) % MOD;
                if(j) d[k][i][j][1] = (d[k][i][j][1] + d[k][i - 1][j - 1][0]) % MOD;
            }

    printf("%lld", (d[0][N - 1][K][0] + d[1][N - 1][K][1] + d[2][N - 1][K][0]) % MOD);
    return 0;
}

