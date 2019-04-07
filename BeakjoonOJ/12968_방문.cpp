//
// Created by Acka on 7/11/16.
//

#include <stdio.h>

int main()
{
    int N, M, K; scanf("%d %d %d", &N, &M, &K);
    printf("%d\n", (K == 1 || !(N & 1) || !(M & 1)));
    return 0;
}
