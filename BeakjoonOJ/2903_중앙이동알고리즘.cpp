//
// Created by Acka on 4/17/16.
//

#include <stdio.h>

int main()
{
    int N; scanf("%d", &N);
    long long int x = 2;
    while(N--) x = 2 * x - 1;
    printf("%lld\n", x * x);
    return 0;
}
