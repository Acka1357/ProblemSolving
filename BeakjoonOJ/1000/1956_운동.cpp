//
// Created by Acka on 2017. 1. 3..
//

#include <stdio.h>
#include <memory.h>

int d[401][401];

int main()
{
    memset(d, 0x3f, sizeof(d));

    int V, E; scanf("%d %d", &V, &E);
    for(int i = 0, u, v, c; i < E; i++){
        scanf("%d %d %d", &u, &v, &c);
        if(c < d[u][v]) d[u][v] = c;
    }

    for(int k = 1; k <= V; k++)
        for(int i = 1; i <= V; i++)
            for(int j = 1; j <= V; j++)
                if(d[i][j] > d[i][k] + d[k][j])
                    d[i][j] = d[i][k] + d[k][j];

    int ans = 0x3f3f3f3f;
    for(int i = 1; i <= V; i++)
        if(d[i][i] < ans) ans = d[i][i];

    printf("%d\n", ans < 0x3f3f3f3f ? ans : -1);
    return 0;
}
