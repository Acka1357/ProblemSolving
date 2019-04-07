//
// Created by Acka on 2017. 11. 8..
//

#include <stdio.h>
#include <algorithm>
using namespace std;

int x[200000];

int main()
{
    int N, C; scanf("%d %d", &N, &C);
    for(int i = 0; i < N; i++)
        scanf("%d", &x[i]);

    sort(x, x + N);

    int l = 0, r = x[N - 1] - x[0], m, ans;
    while(l <= r){
        m = (l + r) / 2;
        int cnt = 1, left = x[0];
        for(int i = 1; i < N; i++)
            if(x[i] - left >= m) cnt++, left = x[i];

        if(cnt >= C) ans = m, l = m + 1;
        else r = m - 1;
    }

    printf("%d\n", ans);
    return 0;
}

