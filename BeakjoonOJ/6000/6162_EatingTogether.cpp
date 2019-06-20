//
// Created by Acka on 10/17/16.
//

#include <stdio.h>
#include <algorithm>
using namespace std;

int x[30000], d[2][30000][4];

int main()
{
    int N; scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", &x[i]);

    for(int i = 1; i <= 3; i++)
        d[0][0][i] = d[1][0][i] = 1;
    d[0][0][x[0]] = d[1][0][x[0]] = 0;

    for(int i = 1; i < N; i++)
        for (int j = 1; j <= 3; j++) {
            d[0][i][j] = d[0][i - 1][1] + (x[i] != j);
            d[1][i][j] = d[1][i - 1][3] + (x[i] != j);
            for (int k = 2; k <= j; k++)
                d[0][i][j] = min(d[0][i][j], d[0][i - 1][k] + (x[i] != j));
            for(int k = 2; j <= k; k--)
                d[1][i][j] = min(d[1][i][j], d[1][i - 1][k] + (x[i] != j));
        }

    int ans = min(d[0][N - 1][1], d[1][N - 1][1]);
    for(int i = 2; i <= 3; i++)
        ans = min(ans, min(d[0][N - 1][i], d[1][N - 1][i]));

    printf("%d\n", ans);
    return 0;
}