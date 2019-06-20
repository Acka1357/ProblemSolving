//
// Created by Acka on 2017. 2. 5..
//

#include <stdio.h>
#include <algorithm>
using namespace std;

#define INF     20000000

int d[16][1 << 16], all;
int N, w[16][16];

int dfs(int cur, int visited){
    if(d[cur][visited]) return d[cur][visited];
    if(visited == all) return w[cur][0] ? w[cur][0] : INF;

    int minc = INF;
    for(int i = 1, b = 2; i < N; i++, b <<= 1)
        if(!(visited & b) && w[cur][i])
            minc = min(minc, dfs(i, visited + b) + w[cur][i]);

    return d[cur][visited] = minc;
}

int main()
{
    scanf("%d", &N);
    all = (1 << N) - 1;

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            scanf("%d", &w[i][j]);

    printf("%d\n", dfs(0, 1));
    return 0;
}
