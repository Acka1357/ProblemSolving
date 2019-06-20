//
// Created by Acka on 4/14/16.
//

#include <stdio.h>

#define MOD 1000000007

int a[100000], b[100000];

int main()
{
    int N; scanf("%d", &N);

    for(int i = 0; i < N; i++) scanf("%d", &a[i]);
    for(int i = 1; i < N; i++) scanf("%d", &b[i - 1]);

    long long int d[2][2], t = 0;
    d[t][0] = a[0]; d[t][1] = b[0];
    for(int i = 1; i < N; i++, t = !t){
        d[!t][0] = (((d[t][0] * (a[i] + b[i - 1])) % MOD) + ((d[t][1] * (a[i] + b[i - 1] - 1)) % MOD)) % MOD;
        d[!t][1] = (((d[t][0] + d[t][1]) * b[i])) % MOD;
    }

    printf("%lld\n", (d[t][0] + d[t][1]) % MOD);
    return 0;
}

