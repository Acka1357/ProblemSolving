//
// Created by Acka on 2017. 8. 11..
//

#include <stdio.h>

int N, M, K;
char map[500][501];
int dr[4] = {0, 1, 0, -1}, dc[4] = {1, 0, -1, 0};
bool chk[500][500];

void dfs(int r, int c){
    chk[r][c] = true;
    for(int i = 0; i < 4; i++){
        int nr = r + dr[i], nc = c + dc[i];
        if(nr < 0|| nc < 0|| nr >= N || nc >= M) continue;
        if(map[nr][nc] != '.' || chk[nr][nc]) continue;
        dfs(nr, nc);
    }

    if(K){
        map[r][c] = 'X';
        K--;
    }
}

int main()
{
    scanf("%d %d %d", &N, &M, &K);
    for(int i = 0; i < N; i++)
        scanf("%s", map[i]);

    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            if(map[i][j] == '.')
                dfs(i, j);

    for(int i = 0; i < N; i++)
        printf("%s\n", map[i]);

    return 0;
}

