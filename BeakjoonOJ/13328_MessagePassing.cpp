//
// Created by Acka on 10/24/16.
//

#include <stdio.h>

#define MOD 31991

int pmat[32][50][50], D, T;

void mat_mult(int ma[][50], int mb[][50], int res[][50]){
    long long int save[50][50] = { 0, };
    for (int i = 0; i < D; i++)
        for (int j = 0; j < D; j++)
            for (int k = 0; k < D; k++)
                save[i][j] += ma[i][k] * mb[k][j];

    for (int i = 0; i < D; i++)
        for (int j = 0; j < D; j++)
            res[i][j] = save[i][j] % MOD;
}

int main()
{
    scanf("%d %d", &D, &T);

    int org[50] = { 1, };
    for (int i = 1; i < D; i++)
        org[i] = (org[i - 1] << 1) % MOD;

    if (T <= D) return 0 & printf("%d\n", org[T - 1]);

    T = T - D;
    for (int i = 0; i < D; i++){
        if (i != D - 1) pmat[1][i][i + 1] = 1;
        pmat[1][D - 1][i] = pmat[0][i][i] = 1;
    }

    long long int mpow = 2, b = 2;
    for (; b <= T; mpow++, b <<= 1)
        mat_mult(pmat[mpow - 1], pmat[mpow - 1], pmat[mpow]);

    for (mpow--, b >>= 1; T; mpow--, b >>= 1)
        if (b <= T){
            mat_mult(pmat[0], pmat[mpow], pmat[0]);
            T -= b;
        }

    int ans = 0;
    for (int i = 0; i < D; i++)
        ans = (ans + pmat[0][D - 1][i] * org[i]) % MOD;

    printf("%d\n", ans);
    return 0;
}
