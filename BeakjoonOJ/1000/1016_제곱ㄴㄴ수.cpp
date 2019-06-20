//
// Created by Acka on 2017. 4. 6..
//

#include <stdio.h>

bool chk[1000001];

int main()
{
    long long A, B; scanf("%lld %lld", &A, &B);
    for(long long i = 2; ; i++){
        long long sq = i * i;
        if(B < sq) break;
        for(long long j = ((A - 1) / sq) * sq + sq; j <= B; j += sq)
            chk[j - A] = true;
    }

    int ans = 0;
    for(int i = B - A; 0 <= i; i--)
        if(!chk[i]) ans++;

    printf("%d\n", ans);
    return 0;
}
