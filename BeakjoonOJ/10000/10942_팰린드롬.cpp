//
// Created by Acka on 5/4/16.
//

#include <stdio.h>

bool d[2000][2000];

int main()
{
    int N, n[2000]; scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", &n[i]);

    for(int i = 0; i < N; i++)
        d[i][i] = true;

    for(int l = 0; l < N; l++)
        for(int i = l + 1, im = N - l - 1; i < im; i++)
            if(d[i - l][i + l]) d[i - l - 1][i + l + 1] = (n[i - l - 1] == n[i + l + 1]);

    int Q, l, r; for(scanf("%d", &Q); Q--;){
        scanf("%d %d", &l, &r);
        printf("%d\n", d[l - 1][r - 1]);
    }

    return 0;
}
