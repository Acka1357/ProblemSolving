//
// Created by Acka on 11/2/16.
//

#include <stdio.h>
#include <memory.h>
#include <algorithm>
using namespace std;

int cost[1500][1500], d[1500][1500];

int main()
{
    int N; scanf("%d", &N);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            scanf("%d", &cost[i][j]);

    memset(d, 0x3f, sizeof(d));
    d[0][0] = 0;
    for(int i = 1; i < N; i++)
        for(int j = 0; j < i; j++){
            d[i][j] = min(d[i][j], d[i - 1][j] + cost[i][i - 1]);
            d[j][i] = min(d[j][i], d[j][i - 1] + cost[i - 1][i]);
            d[i - 1][i] = min(d[i - 1][i], d[i - 1][j] + cost[j][i]);
            d[i][i - 1] = min(d[i][i - 1], d[j][i - 1] + cost[j][i]);

        }

    int ans = d[0][N - 1];
    for(int i = 0; i < N; i++)
        ans = min(ans, min(d[i][N - 1], d[N - 1][i]));

    printf("%d\n", ans);
    return 0;
}
