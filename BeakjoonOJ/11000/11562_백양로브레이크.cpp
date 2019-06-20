//
// Created by Acka on 2017. 1. 3..
//

#include <stdio.h>
#include <memory.h>

int d[251][251];

int main()
{
    int N, M; scanf("%d %d", &N, &M);

    memset(d, 0x3f, sizeof(d));
    for(int i = 1; i <= N; i++) d[i][i] = 0;
    for(int i = 0, u, v, b; i < M; i++){
        scanf("%d %d %d", &u, &v, &b);
        d[u][v] = 0;
        d[v][u] = 1 - b;
    }

    for(int k = 1; k <= N; k++)
        for(int i = 1; i <= N; i++)
            for(int j = 1; j <= N; j++)
                if(d[i][j] > d[i][k] + d[k][j])
                    d[i][j] = d[i][k] + d[k][j];

    int K, u, v; for(scanf("%d", &K); K--;){
        scanf("%d %d", &u, &v);
        printf("%d\n", d[u][v]);
    }

    return 0;
}
