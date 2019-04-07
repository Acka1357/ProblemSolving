//
// Created by Acka on 2017. 11. 17..
//

#include <stdio.h>

int main()
{
    int N, L, W, H; scanf("%d %d %d %d", &N, &L, &W, &H);

    int cnt = 100000;
    long double l = 0, r = (L < W ? (L < H ? L : H) : (W < H ? W : H)), m, ans;
    while(cnt--){
        m = (l + r) / 2;
        long long tmp = H / m;
        if((long long)(L / m) * (int)(W / m) >= (N + tmp - 1) / tmp) ans = m, l = m;
        else r = m;
    }

    printf("%.10Lf\n", ans);
    return 0;
}
