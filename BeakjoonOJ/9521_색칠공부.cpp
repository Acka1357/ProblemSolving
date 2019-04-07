//
// Created by Acka on 2017. 6. 14..
//

#include <stdio.h>

#define MOD     1000000007

int f[1000001], d[1000001], th[1000001];

int cycle_size(int cur, int t){
    if(th[cur]) return t - th[cur];
    th[cur] = t;
    return cycle_size(f[cur], t + 1);
}

int main()
{
    int N, K; scanf("%d %d", &N, &K);
    for(int i = 1; i <= N; i++)
        scanf("%d", &f[i]);

    d[0] = 1; d[1] = K; d[2] = K * (K - 1);
    d[3] = K * (K - 1) * (K - 2);
    long long r = ((K - 2) * (K - 2) + K - 1) % MOD;
    for(int i = 4; i <= N; i++)
        d[i] = (d[i - 2] * r) % MOD;

    int linear = N, ret;
    for(int i = 1; i <= N; i++)
        if(!th[i]){

        }

    return 0;
}
