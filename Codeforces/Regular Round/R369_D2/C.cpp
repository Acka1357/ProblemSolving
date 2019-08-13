//
// Created by Acka on 8/29/16.
//

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <stack>
#include <memory.h>
using namespace std;

long long int d[100][102][101];
long long int cost[100][101];

int main()
{
    int N, M, K; scanf("%d %d %d", &N, &M, &K);

    int org[100];
    for(int i = 0; i < N; i++)
        scanf("%d", &org[i]);

    for(int i = 0; i < N; i++)
        for(int j = 1; j <= M; j++)
            scanf("%lld", &cost[i][j]);

    memset(d, 0xff, sizeof(d));
    if(org[0]) d[0][1][org[0]] = 0;
    else{
        for(int i = 1; i <= M; i++)
            d[0][1][i] = cost[0][i];
    }

    for(int i = 1; i < N; i++) {
        if(!org[i]) {
            for (int j = 1, jm = min(i, K); j <= jm; j++)
                for (int k = 1; k <= M; k++){
                    if(d[i - 1][j][k] < 0) continue;
                    for(int c = 1; c <= M; c++){
                        if(c == k){
                            if(d[i][j][c] < 0) d[i][j][c] = d[i - 1][j][k] + cost[i][c];
                            else d[i][j][c] = min(d[i][j][c], d[i - 1][j][k] + cost[i][c]);
                        }
                        else {
                            if(d[i][j + 1][c] < 0) d[i][j + 1][c] = d[i - 1][j][k] + cost[i][c];
                            else d[i][j + 1][c] = min(d[i][j + 1][c], d[i - 1][j][k] + cost[i][c]);
                        }
                    }
                }
        }
        else{
            for(int j = 1, jm = min(i, K); j <= jm; j++)
                for(int k = 1; k <= M; k++){
                    if(d[i - 1][j][k] < 0) continue;
                    if(k == org[i]){
                        if(d[i][j][org[i]] < 0) d[i][j][org[i]] = d[i - 1][j][k];
                        else d[i][j][org[i]] = min(d[i][j][org[i]], d[i - 1][j][k]);
                    }
                    else{
                        if(d[i][j + 1][org[i]] < 0) d[i][j + 1][org[i]] = d[i - 1][j][k];
                        else d[i][j + 1][org[i]] = min(d[i][j + 1][org[i]], d[i - 1][j][k]);
                    }
                }
        }
    }

//    for(int i = 0; i < N; i++)
//        for(int j = 1; j <= K; j++){
//            printf("(%d, %d): ", i, j);
//            for(int k = 1; k <= M; k++)
//                printf("%3d ", d[i][j][k]);
//            printf("\n");
//        }

    long long int ans = -1;
    for(int i = 1; i <= M; i++)
        if(0 <= d[N - 1][K][i]){
            if(ans < 0) ans = d[N - 1][K][i];
            else ans = min(ans, d[N - 1][K][i]);
        }

    printf("%lld\n", ans);
    return 0;
}

