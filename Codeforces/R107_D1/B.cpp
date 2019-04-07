//
// Created by Acka on 2017. 4. 3..
//

#include <stdio.h>

#define MOD 1000000007

int N, M, K;

long long pow(long long x, long long ex){
    long long int ans = 1;
    while(ex){
        if(ex & 1) ans = (ans * x) % MOD;
        x = (x * x) % MOD;
        ex >>= 1;
    }
    return ans;
}

int main() {
    scanf("%d %d %d", &N, &M, &K);
    if(N < K || K == 1) printf("%lld\n", pow(M, N));
    else if(K == N) printf("%lld\n", pow(M, (K + 1) / 2));
    else if(K & 1) printf("%lld\n", pow(M , 2));
    else printf("%d\n", M);
    return 0;
}
