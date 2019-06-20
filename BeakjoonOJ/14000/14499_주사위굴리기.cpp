//
// Created by Acka on 2017. 4. 15..
//

#include <stdio.h>

int map[20][20], dice[1001][7];
int dr[5] = {0, 0, 0, -1, 1}, dc[5] = {0, 1, -1, 0, 0};
int next[5][7] = {
        {0, 0, 0, 0, 0, 0, 0,},
        {0, 4, 2, 1, 6, 5, 3},
        {0, 3, 2, 6, 1, 5, 4},
        {0, 5, 1, 3, 4, 6, 2},
        {0, 2, 6, 3, 4, 1, 5}
};

int main()
{
    int N, M, r, c, K;
    scanf("%d %d %d %d %d", &N, &M, &r, &c, &K);

    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            scanf("%d", &map[i][j]);

    int top = 1, btm = 6;
    for(int i = 1; i <= K; i++){
        int d; scanf("%d", &d);

        int nr = r + dr[d], nc = c + dc[d];
        if(nr < 0 || nc < 0 || N <= nr || M <= nc){
            i--; K--;
            continue;
        }

        for(int j = 1; j <= 6; j++)
            dice[i][next[d][j]] = dice[i - 1][j];

        if(map[nr][nc]){
            dice[i][btm] = map[nr][nc];
            map[nr][nc] = 0;
        }
        else map[nr][nc] = dice[i][btm];

        printf("%d\n", dice[i][top]);
        r = nr; c = nc;
    }
    return 0;
}

