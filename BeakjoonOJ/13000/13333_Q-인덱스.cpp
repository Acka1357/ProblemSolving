//
// Created by Acka on 2017. 1. 19..
//

#include <stdio.h>
#include <algorithm>
using namespace std;

int acc[10001];

int main()
{
    int N; scanf("%d", &N);
    for(int i = 0, x; i < N; i++){
        scanf("%d", &x);
        acc[x]++;
    }

    for(int i = 1; i <= 10000; i++)
        acc[i] += acc[i - 1];

    for(int i = 0; i <= N; i++)
        if(N - i <= acc[i] && i <= N - acc[max(0, i - 1)])
            return 0 & printf("%d\n", i);

    return 0;
}
