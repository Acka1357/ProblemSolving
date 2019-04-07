//
// Created by Acka on 2017. 8. 7..
//

#include <stdio.h>

int x[1000], y[1000], s[1000];

int main()
{
    int N, S; scanf("%d %d", &N, &S);

    int sum = 0;
    for(int i = 0; i < N; i++) {
        scanf("%d %d %d", &x[i], &y[i], &s[i]);
        sum += s[i];
    }
    if(S + sum < 1000000) return 0 & printf("-1\n");

    double l = 0, r = 100000, m;
    while(r - l > 1e-9){
        m = (l + r) / 2;
        sum = S;
        for(int i = 0; i < N; i++)
            if(x[i] * x[i] + y[i] * y[i] <= m * m) sum += s[i];
        if(sum >= 1000000) r = m;
        else l = m;
    }

    printf("%.10lf\n", l);
    return 0;
}

