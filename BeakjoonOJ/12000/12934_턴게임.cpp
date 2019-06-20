//
// Created by Acka on 7/8/16.
//

#include <stdio.h>

int main()
{
    long long int A, B; scanf("%lld %lld", &A, &B);

    long long int R = 1, sum = 2 * (A + B);
    while(R * (R + 1) < sum) R++;
    if(R * (R + 1) != sum){
        printf("-1\n"); return 0;
    }

    long long int scr = 0, cnt = 0;
    while(R && A){
        if(R <= A){
            A -= R; cnt++;
        }
        R--;
    }

    printf("%lld\n", cnt);
    return 0;
}

