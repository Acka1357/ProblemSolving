//
// Created by Acka on 2017. 4. 14..
//

#include <stdio.h>

int a[50][50], b[50][50];

int main()
{
    int N, M; scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            scanf("%1d", &a[i][j]);

    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            scanf("%1d", &b[i][j]);

    int ans = 0;
    for(int i = 0; i < N - 2; i++)
        for(int j = 0; j < M - 2; j++)
            if(a[i][j] != b[i][j]){
                ans++;
                for(int r = 0; r < 3; r++)
                    for(int c = 0; c < 3; c++)
                        a[i + r][j + c] = 1 - a[i + r][j + c];
            }

    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            if(a[i][j] != b[i][j]) ans = -1;

    printf("%d\n", ans);
    return 0;
}
