//
// Created by Acka on 2017. 1. 14..
//

#include <stdio.h>

int d[1000001] = {-1000000001};

int main()
{
    int N, ans = 0; scanf("%d", &N);

    for(int i = 1, x; i <= N; i++){
        scanf("%d", &x);

        int l = 0, r = ans + 1, m;
        while(l < r){
            m = (l + r) / 2;
            if(d[m] < x) l = m + 1;
            else r = m;
        }

        if(ans < r) ans = r;
        d[r] = x;
    }

    printf("%d\n", ans);
    return 0;
}
