//
// Created by Acka on 2017. 12. 16..
//

#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <queue>
#include <vector>
#include <functional>
#include <memory.h>
using namespace std;

int main()
{
    long long N, A, B; scanf("%lld %lld %lld", &N, &A, &B);

    long long ansx = - 1, ansy = -1;
    for(int i = 0; A * i <= N; i++)
        if((N - A * i) % B == 0){
            ansx = i;
            ansy = (N - A * i) / B;
        }

    if(ansx < 0) return 0 & printf("NO\n");
    else{
        printf("YES\n%lld %lld\n", ansx, ansy);
    }

    return 0;
}

