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

int main()
{
    int N, M; scanf("%d %d", &N, &M);
    printf("%d\n", M - gcd(N, M));
    return 0;
}
