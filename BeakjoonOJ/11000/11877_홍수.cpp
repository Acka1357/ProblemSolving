//
// Created by Acka on 2017. 7. 5..
//

#include <stdio.h>

bool need[1000000];

int main()
{
    long long N, K; scanf("%lld %lld", &N, &K);
    if(K > ((N - 1) * (N - 2)) / 2)
        return 0 & printf("-1\n");

    for(int i = 1; i < N - 1 && K; i++)
        if(K >= N - 1 - i){
            need[i] = true;
            K -= N - 1 - i;
        }

    printf("%lld ", N);
    for(int i = 1; i < N - 1; i++)
        if(need[i]) printf("%d ", i);
    for(int i = N - 1; i >= 1; i--)
        if(!need[i]) printf("%d ", i);
    printf("\n");

    return 0;
}
