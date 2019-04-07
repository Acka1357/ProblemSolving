//
// Created by Acka on 4/18/16.
//

#include <stdio.h>

int gcd(int a, int b){
    int c;
    while(b){
        c = a; a = b; b = c % b;
    }
    return a;
}

long long int comb3(long long int x){
    return (((x * (x - 1)) / 2) * (x - 2)) / 3;
}

int main()
{
    long long int N, M; scanf("%lld %lld", &N, &M);
    long long int ans = comb3((N + 1) * (M + 1)), g;
    ans -= (M + 1) * comb3(N + 1) + (N + 1) * comb3(M + 1);

    for(int i = 2; i <= N; i++)
        for(int j = 2; j <= M; j++)
            if(1 < (g = gcd(i, j)))
               ans -= 2 * (g - 1) * (N - i + 1) * (M - j + 1);

    printf("%lld\n", ans);
    return 0;
}

