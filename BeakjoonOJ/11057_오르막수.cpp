//
// Created by Acka on 2017. 3. 17..
//

#include <stdio.h>

#define MOD     10007

int d[1001][10];

int main()
{
    d[0][0] = 1;

    int N; scanf("%d", &N);
    for(int i = 1; i <= N; i++)
        for(int j = 0; j < 10; j++)
            for(int k = 0; k <= j; k++)
                d[i][j] = (d[i][j] + d[i - 1][k]) % MOD;

    int ans = 0;
    for(int i = 0; i < 10; i++)
        ans = (ans + d[N][i]) % MOD;

    printf("%d\n", ans);
    return 0;
}
