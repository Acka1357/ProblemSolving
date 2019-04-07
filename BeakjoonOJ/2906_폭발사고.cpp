//
// Created by Acka on 2017. 9. 7..
//

#include <stdio.h>

#define MOD     10301

long long dl[1001][1001], dr[1001][1001];
long long lsum[1001], rsum[1001];

int main()
{
    int N, A, B; scanf("%d %d %d", &N, &A, &B);

    int L = A, R = N - B;
    dl[L][A] = dr[R][B] = 1;
    for(int i = L; i <= R ; i++)
        for(int j = N; j >= A; j--){
            if(!dl[i][j]) continue;
            dl[i][j] %= MOD;
            for(int k = (R + j - i) / 2; k >= j; k--)
                dl[i + 2 * k - j][k] += dl[i][j];
        }
    for(int i = R; i >= L; i--)
        for(int j = N; j >= B; j--){
            if(!dr[i][j]) continue;
            dr[i][j] %= MOD;
            for(int k = (i + j - L) / 2; k >= j; k--)
                dr[i - 2 * k + j][k] += dr[i][j];
        }

    for(int i = 1; i < N; i++){
        for(int j = A; j <= N; j++)
            lsum[i] += dl[i][j];
        lsum[i] %= MOD;
    }
    for(int i = N - 1; i > 0; i--){
        for(int j = B; j <= N; j++)
            rsum[i] += dr[i][j];
        rsum[i] %= MOD;
    }


    long long ans = 0;
    for(int i = L; i <= R; i++)
        for(int j = i; j <= R; j++)
            ans = (ans + lsum[i] * rsum[j]) % MOD;

    printf("%lld\n", ans);
    return 0;
}
