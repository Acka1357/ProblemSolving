//
// Created by Acka on 4/13/16.
//

#include <stdio.h>
#include <memory.h>
#include <algorithm>
using namespace std;

int d[2222][2222];
int n[2222][2222];

int main()
{
    int N; scanf("%d", &N);

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            scanf("%d", &n[i][j]);

    memset(d, 0x3f, sizeof(d));
    d[0][0] = 0;
    for(int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            if (j < N - 1)
                d[i][j + 1] = min(d[i][j + 1], d[i][j] + (n[i][j] <= n[i][j + 1] ? (n[i][j + 1] - n[i][j] + 1) : 0));
            if (i < N - 1)
                d[i + 1][j] = min(d[i + 1][j], d[i][j] + (n[i][j] <= n[i + 1][j] ? (n[i + 1][j] - n[i][j] + 1) : 0));
        }

    printf("%d\n", d[N - 1][N - 1]);
    return 0;
}

