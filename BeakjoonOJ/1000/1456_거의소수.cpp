//
// Created by Acka on 2017. 8. 6..
//

#include <stdio.h>

bool notP[10000001] = {true, true, };
long long p[664579], pcnt;

void set_prime(){
    for(long long i = 2; i <= 10000000; i++){
        if(notP[i]) continue;
        p[pcnt++] = i;
        for(long long j = i * i; j <= 10000000; j += i)
            notP[j] = true;
    }
}

int main()
{
    set_prime();
    long long A, B; scanf("%lld %lld", &A, &B);

    int ans = 0;
    for(int i = 0; i < pcnt; i++){
        for(long long pow = p[i]; pow <= B / p[i]; pow *= p[i])
            if(A <= pow * p[i]) ans++;
    }

    printf("%d\n", ans);
    return 0;
}
