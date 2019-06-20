//
// Created by Acka on 2017. 10. 20..
//

#include <stdio.h>
#include <algorithm>
#include <memory.h>
using namespace std;

int map[1001][3], d[3003][1001][8];

int main()
{
    memset(d, 0xbf, sizeof(d));

    int N, K; scanf("%d %d", &N, &K);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < 3; j++)
            scanf("%d", &map[i][j]);

    d[0][0][0] = 0;
    for(int i = 0; i < 3 * N; i++){
        int r = i / 3, c = i % 3;
        for(int k = 0; k <= K; k++){
            for(int j = 0; j < 8; j++){
                d[i + 1][k][j >> 1] = max(d[i + 1][k][j >> 1], d[i][k][j]);
                if(k == K) continue;
                if(!(j & 1)) d[i + 1][k + 1][(j >> 1) + 4] = max(d[i + 1][k + 1][(j >> 1) + 4], d[i][k][j] + map[r][c] + map[r + 1][c]);
                if(!(j & 3) && c != 2) d[i + 1][k + 1][(j >> 1) + 1] = max( d[i + 1][k + 1][(j >> 1) + 1], d[i][k][j] + map[r][c] + map[r][c + 1]);
            }
        }
    }

    printf("%d\n", d[3 * N][K][0]);
    return 0;
}
