//
// Created by Acka on 2017. 1. 3..
//

#include <stdio.h>

bool d[100][100];

int main()
{
    int N, M; scanf("%d %d", &N, &M);
    for(int i = 0, u, v; i < M; i++){
        scanf("%d %d", &u, &v);
        d[u - 1][v - 1] = true;
    }

    for(int i = 0; i < N; i++) d[i][i] = true;
    for(int k = 0; k < N; k++)
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                if(d[i][k] && d[k][j]) d[i][j] = true;

    for(int i = 0; i < N; i++) {
        int ans = 0;
        for (int j = 0; j < N; j++)
            if (!d[i][j] && !d[j][i]) ans++;
        printf("%d\n", ans);
    }

    return 0;
}
