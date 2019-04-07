//
// Created by Acka on 8/9/16.
//

#include <stdio.h>

long long absx(long long x){
    return x < 0 ? -x : x;
}

int main()
{
    long long int X, Y, N; scanf("%lld %lld %lld", &X, &Y, &N);

    long long int a = 0, b = 1;
    double mind = (double)X / Y;
    for(long long int d = 1; d <= N; d++){
        long long int u = (d * X) / Y;
        long long int us[3] = {u - 1, u, u + 1};
        for(int i = 0; i < 3; i++) {
            if(us[i] < 0) continue;
            if (absx(d * X - Y * us[i]) / (double)(Y * d) < mind) {
                mind = absx(d * X - Y * us[i]) / (double)(Y * d);
                a = us[i];
                b = d;
            }
        }
    }

    printf("%lld/%lld\n", a, b);
    return 0;
}
