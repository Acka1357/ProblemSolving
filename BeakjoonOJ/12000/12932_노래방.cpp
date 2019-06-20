//
// Created by Acka on 7/8/16.
//

#include <stdio.h>
#include <algorithm>
#include <memory.h>
using namespace std;

int d[2001][2001];

int main()
{
    int N; scanf("%d", &N);

    int n[2001], maxn = (1ll << 31) - 1;
    for(int i = 1; i <= N; i++)
        scanf("%d", &n[i]);

    memset(d, 0xff, sizeof(d));
    for(int i = 1; i <= N; i++) {
        for (int j = 0; j < i - 1; j++) {
            d[i][j] = d[i - 1][j];
        }
    }

    int ans = maxn;
    for(int i = 0; i < N; i++)
        ans = min(ans, min(d[i][N], d[N][i]));

    printf("%d\n", ans);

    return 0;
}

