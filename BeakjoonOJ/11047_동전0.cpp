//
// Created by Acka on 2017. 1. 6..
//

#include <stdio.h>

int main()
{
    int N, K; scanf("%d %d", &N, &K);

    int a[10], sum = 0;
    for(int i = 0; i < N; i++)
        scanf("%d", &a[i]);

    for(int i = N - 1; 0 <= i; i--){
        sum += K / a[i];
        K -= a[i] * (K / a[i]);
    }

    printf("%d\n", sum);
    return 0;
}
