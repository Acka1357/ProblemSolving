//
// Created by Acka on 8/8/16.
//

#include <stdio.h>

int main()
{
    int dr[4] = {1, 1, 1, 2}, dc[4] = {-1, 0, 1, 0};

    int N; scanf("%d", &N);

    char map[100][101];
    for(int i = 0; i < N; i++)
        scanf("%s", map[i]);

    bool chk = true;
    for(int i = 0; i < N && chk; i++)
        for(int j = 0; j < N && chk; j++)
            if(map[i][j] == '#'){
                map[i][j] = 0;
                for(int k = 0; k < 4; k++){
                    int nr = i + dr[k], nc = j + dc[k];
                    if(nc < 0 || N <= nr || N <= nc){
                        chk = false; break;
                    }
                    if(map[nr][nc] != '#'){
                        chk = false; break;
                    }
                    map[nr][nc] = 0;
                }
            }

    printf("%s\n", chk ? "YES" : "NO");
    return 0;
}
