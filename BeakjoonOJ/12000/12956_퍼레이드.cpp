//
// Created by Acka on 7/11/16.
//

#include <stdio.h>
#include <queue>
#include <vector>
#include <memory.h>
#include <algorithm>
using namespace std;

#define INF 0x3f3f3f3f

int N, M;
int d1[100][100], d2[100][100], e[2000][3];

int main()
{
    scanf("%d %d", &N, &M);

    memset(d1, 0x3f, sizeof(d1));

    int e[2000][3];
    for(int i = 0; i < M; i++) {
        scanf("%d %d %d", &e[i][0], &e[i][1], &e[i][2]);
        d1[e[i][0]][e[i][1]] = d1[e[i][1]][e[i][0]] = e[i][2];
    }

    for(int k = 0; k < N; k++)
        for(int i = 0; i < N; i++){
            if(INF <= d1[i][k]) continue;
            for(int j = 0; j < N; j++)
                if(d1[k][j] < INF)
                    d1[i][j] = min(d1[i][j], d1[i][k] + d1[k][j]);
        }

    for(int ee = 0; ee < M; ee++){
        memset(d2, 0x3f, sizeof(d2));

        for(int i = 0; i < M; i++)
            if(i != ee) d2[e[i][0]][e[i][1]] = d2[e[i][1]][e[i][0]] = e[i][2];

        for(int k = 0; k < N; k++)
            for(int i = 0; i < N; i++){
                if(INF <= d1[i][k]) continue;
                for(int j = 0; j < N; j++)
                    if(d2[k][j] < INF)
                        d2[i][j] = min(d2[i][j], d2[i][k] + d2[k][j]);
            }

        int cnt = 0;
        for(int i = 0; i < N; i++)
            for(int j = i + 1; j < N; j++)
                if(d1[i][j] != d2[i][j]) cnt++;

        printf("%d ", cnt);
    }

    printf("\n");
    return 0;
}
