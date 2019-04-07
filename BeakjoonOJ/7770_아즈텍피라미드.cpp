
//
// Created by Acka on 4/14/16.
//

#include <stdio.h>

int main()
{
    int N; scanf("%d", &N);

    long long int ans = 0, need = 1;
    for(int add = 4; need <= N; add += 4){
        N -= need; ans++; need += add;
    }

    printf("%lld\n", ans);
    return 0;
}
