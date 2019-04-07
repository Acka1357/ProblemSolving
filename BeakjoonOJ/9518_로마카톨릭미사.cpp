//
// Created by Acka on 2017. 8. 16..
//

#include <stdio.h>

int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
char map[50][51];

int main()
{
    int R, S; scanf("%d %d", &R, &S);
    for(int i = 0; i < R; i++)
        scanf("%s", map[i]);

    int ans = 0, add = 0;
    for(int i = 0; i < R; i++)
        for(int j = 0; j < S; j++){
            int cnt = 0;
            for(int k = 0; k < 8; k++){
                int nr = i + dr[k], nc = j + dc[k];
                if(nr < 0 || nc < 0 || nr >= R || nc >= S) continue;
                if(map[nr][nc] == 'o') cnt++;
            }
            if(map[i][j] == 'o') ans += cnt;
            else if(add < cnt) add = cnt;
        }

    printf("%d\n", ans / 2 + add);
    return 0;
}
