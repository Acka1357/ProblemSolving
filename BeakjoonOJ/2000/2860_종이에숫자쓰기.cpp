//
// Created by Acka on 2017. 10. 11..
//

#include <stdio.h>

long long get_gcd(long long a, long long b){
    long long temp;
    while(b){
        temp = a;
        a = b; b = temp % b;
    }
    return a;
}

char s[12];

int main()
{
    scanf("%s", s);

    long long t = s[0] - '0', b = 1;
    for(int i = 2; s[i]; i++, b *= 10){
        t *= 10; t += s[i] - '0';
    }

    long long g = get_gcd(t, b);
    t /= g; b /= g;

    long long ans[6];
    for(int i = 5; i >= 1; i--){
        long long l = 0, r = t / i, m, cnt = 0;
        while(l <= r){
            m = (l + r) / 2;
            if(b - m <= t - m * i){
                cnt = m;
                l = m + 1;
            }
            else r = m - 1;
        }
        t -= cnt * i; b -= cnt;
        ans[i] = cnt;
    }

    for(int i = 1; i <= 5; i++)
        printf("%lld ", ans[i]);
    printf("\n");

    return 0;
}
