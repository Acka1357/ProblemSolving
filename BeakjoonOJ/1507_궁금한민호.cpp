//
// Created by Acka on 2017. 1. 3..
//

#include <stdio.h>

bool chk[20][20];
int d[20][20];

int main()
{
    int N, ans = 0; scanf("%d", &N);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++) {
            scanf("%d", &d[i][j]);
            ans += d[i][j];
        }

    for(int k = 0; k < N; k++)
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++) {
                if(d[i][k] + d[k][j] < d[i][j]) return printf("-1\n");
                if(!chk[i][j] && i != k && j != k && d[i][j] == d[i][k] + d[k][j]) {
                    ans -= d[i][j];
                    chk[i][j] = true;
                }
            }

    printf("%d\n", ans >> 1);
    return 0;
}
