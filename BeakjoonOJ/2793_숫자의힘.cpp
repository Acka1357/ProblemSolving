//
// Created by Acka on 2017. 8. 23..
//

#include <stdio.h>

int str[51] = {0, 0, 1};

long long get_gcd(long long a, long long b){
    long long temp;
    while(b){
        temp = a; a = b; b = temp % b;
    }
    return a;
}

long long get_strength(long long X){
    long long d = 1, gcd, sum = 0;
    for(int i = 2; d <= X; i++){
        gcd = get_gcd(d, i);
        sum += (X / d - (i - 1) / d - X / ((d / gcd) * i)) * (str[i] + 1);
        d = (d / gcd) * i;
    }
    return sum;
}

int main()
{
    for(int i = 3; i <= 50; i++)
        for(int j = 2; j < i; j++)
            if(i % j){
                str[i] = str[j] + 1;
                break;
            }

    long long A, B; scanf("%lld %lld", &A, &B);
    printf("%lld\n", get_strength(B) - get_strength(A - 1));

    return 0;
}
