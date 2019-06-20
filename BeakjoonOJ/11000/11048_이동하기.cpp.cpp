//
// Created by Acka on 5/4/16.
//

#include <stdio.h>
#include <algorithm>
using namespace std;

int map[1000][1000], d[1000][1000];

int main()
{
    int N, M; scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            scanf("%d", &map[i][j]);

    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++){
            if(i && j) d[i][j] = d[i - 1][j - 1];
            if(i) d[i][j] = max(d[i][j], d[i - 1][j]);
            if(j) d[i][j] = max(d[i][j], d[i][j - 1]);
            d[i][j] += map[i][j];
        }

    printf("%d\n", d[N - 1][M - 1]);
    return 0;
}
