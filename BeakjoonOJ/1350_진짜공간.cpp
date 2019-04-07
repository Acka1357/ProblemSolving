//
// Created by Acka on 4/18/16.
//

#include <stdio.h>

int main()
{
    int N, n[1000]; scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", &n[i]);

    long long int ans = 0, x; scanf("%lld", &x);
    for(int i = 0; i < N; i++)
        ans += (n[i] / x + (n[i] % x != 0)) * x;

    printf("%lld\n", ans);
    return 0;
}
