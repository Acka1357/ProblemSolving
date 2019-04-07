//
// Created by Acka on 2017. 1. 2..
//

#include <stdio.h>
#include <memory.h>

int d[101][101];

int main()
{
    memset(d, 0x3f, sizeof(d));

    int N, M; scanf("%d %d", &N, &M);
    for(int i = 0, u, v, c; i < M; i++){
        scanf("%d %d %d", &u, &v, &c);
        if(c < d[u][v]) d[u][v] = c;
    }

    for(int i = 1; i <= N; i++) d[i][i] = 0;
    for(int k = 1; k <= N; k++)
        for(int i = 1; i <= N; i++)
            for(int j = 1; j <= N; j++)
                if(d[i][k] + d[k][j] < d[i][j])
                    d[i][j] = d[i][k] + d[k][j];

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++)
            printf("%d ", 0x3f3f3f3f <= d[i][j] ? 0 : d[i][j]);
        printf("\n");
    }
    return 0;
}
