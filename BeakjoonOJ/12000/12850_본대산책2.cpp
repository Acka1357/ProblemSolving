//
// Created by Acka on 2017. 2. 17..
//

#include <stdio.h>

#define MOD     1000000007

long long int d[8][8] = {
        0, 1, 1, 0, 0, 0, 0, 0,
        1, 0, 1, 1, 0, 0, 0, 0,
        1, 1, 0, 1, 1, 0, 0, 0,
        0, 1, 1, 0, 1, 1, 0, 0,
        0, 0, 1, 1, 0, 1, 0, 1,
        0, 0, 0, 1, 1, 0, 1, 0,
        0, 0, 0, 0, 0, 1, 0, 1,
        0, 0, 0, 0, 1, 0, 1, 0
};

long long int temp[8][8], ans[8][8];
void mat_mult(long long a[][8], long long b[][8], long long c[][8]){
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++) {
            temp[i][j] = 0;
            for (int k = 0; k < 8; k++)
                temp[i][j] += a[i][k] * b[k][j];
        }

    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
            c[i][j] = temp[i][j] %= MOD;
}

int main()
{
    int N; scanf("%d", &N);

    for(int i = 0; i < 8; i++)
        ans[i][i] = 1;

    for(long long n = 1; n <= N; n <<= 1) {
        if (N & n) mat_mult(ans, d, ans);
        mat_mult(d, d, d);
    }

    printf("%lld\n", ans[0][0]);
    return 0;
}
