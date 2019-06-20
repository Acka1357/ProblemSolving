//
// Created by Acka on 2017. 9. 14..
//

#include <stdio.h>
#include <memory.h>
#include <algorithm>
using namespace std;

#define MOD     1000000007

long long d[2][1 << 18];

int main()
{
    int N, M; scanf("%d %d", &N, &M);
    if(N < M) swap(N, M);

    d[0][0] = d[0][1 << M] = 1;
    int maxs = (1 << (M + 1)), last = (1 << M), t = 0, nt = 1;
    for(int i = 0, im = N * M - 1; i < im; i++, t = !t, nt = !nt){
        memset(d[nt], 0, maxs * sizeof(d[nt][0]));
        for(int s = 0; s < maxs; s++){
            if(!d[t][s]) continue;
            d[t][s] %= MOD;
            d[nt][s >> 1] += d[t][s];
            if(i % M == M - 1 || (s & 3) != 3 || !(s & last))
                d[nt][(s >> 1) + last] += d[t][s];
        }
    }

    long long ans = 0;
    for(int i = 0; i < maxs; i++)
        ans = (ans + d[t][i]) % MOD;
    printf("%lld\n", ans % MOD);

    return 0;
}

