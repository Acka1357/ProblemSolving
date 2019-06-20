//
// Created by Acka on 7/5/16.
//

#include <stdio.h>

int main()
{
    long long int d[61] = {1, 1,};

    int N; scanf("%d", &N);
    for(int i = 2; i <= N; i++) {
        for (int j = 2; j <= i; j++)
            d[i] += d[j - 2] * 2;
        d[i]++;
    }

    printf("%lld\n", d[N]);
    return 0;
}
