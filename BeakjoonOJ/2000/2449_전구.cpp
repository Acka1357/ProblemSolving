//
// Created by Acka on 6/5/16.
//

#include <stdio.h>
#include <memory.h>
#include <algorithm>
using namespace std;

int d[200][200][20];

int main()
{
    memset(d, 0x3f, sizeof(d));

    int N, K; scanf("%d %d", &N, &K);

    for(int i = 0, c; i < N; i++){
        scanf("%d", &c);
        for(int k = 0; k < K; k++)
            d[i][i][k] = 1;
        d[i][i][c - 1] = 0;
    }

    for(int l = 1; l < N; l++)
        for(int r = l; r < N; r++)
            for(int m = r - l; m < r; m++) {
                int minl = d[r - l][m][0], minr = d[m + 1][r][0];
                for(int k = 1; k < K; k++) {
                    minl = min(minl, d[r - l][m][k]);
                    minr = min(minr, d[m + 1][r][k]);
                }
                for (int k = 0; k < K; k++)
                    d[r - l][r][k] = min(d[r - l][r][k], min(min(minl + minr + 2, d[r - l][m][k] + d[m + 1][r][k]),
                                         min(d[r - l][m][k] + minr, minl + d[m + 1][r][k]) + 1));
            }

    int ans = d[0][N - 1][0];
    for(int i = 1; i < K; i++)
        ans = min(ans, d[0][N - 1][i]);

    printf("%d\n", ans);
    return 0;
}

