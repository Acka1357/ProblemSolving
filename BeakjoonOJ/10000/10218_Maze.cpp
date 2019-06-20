//
// Created by Acka on 2017. 7. 13..
//

#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

struct Crd{
    int r, c;
    Crd(){}
    Crd(int r, int c):r(r), c(c){}
};

int N, M;
char map[10][11], ans_s[11], cur_s[11], dir_s[5] = "LRUD";
Crd ncrd[10][10][4];  // L, R, U, D
int dr[4] = {0, 0, -1, 1}, dc[4] = {-1, 1, 0, 0,};
queue<Crd> q[11];

bool lean(int step, int pastd){
    if(q[step].empty()){
        cur_s[step] = '\0';
        strcpy(ans_s, cur_s);
        return true;
    }
    if(step >= 10) return false;

    int size = q[step].size();
    for(int d = 0; d < 4; d++){
        if(pastd / 2 == d / 2) continue;

        while(!q[step + 1].empty()) q[step + 1].pop();
        for(int i = 0; i < size; i++){
            Crd cur = q[step].front();
            if(map[ncrd[cur.r][cur.c][d].r][ncrd[cur.r][cur.c][d].c] != 'O')
                q[step + 1].push(ncrd[cur.r][cur.c][d]);
            q[step].push(cur);
            q[step].pop();
        }
        cur_s[step] = dir_s[d];
        if(lean(step + 1, d)) return true;
        cur_s[step] = 0;
    }

    return false;
}

int main()
{
    int tc; for(scanf("%d", &tc); tc--;){
        scanf("%d %d", &N, &M);
        for(int i = 0; i < N; i++)
            scanf("%s", map[i]);

        while(!q[0].empty()) q[0].pop();
        for(int i = 1; i < N - 1; i++)
            for(int j = 1; j < M - 1; j++)
                if(map[i][j] == '.'){
                    q[0].push(Crd(i, j));
                    for(int k = 0; k < 4; k++){
                        int nr = i, nc = j;
                        while(map[nr][nc] == '.')
                            nr += dr[k], nc += dc[k];
                        ncrd[i][j][k] = (map[nr][nc] == 'O' ? Crd(nr, nc) : Crd(nr - dr[k], nc - dc[k]));
                    }
                }

        strcpy(ans_s, "XHAE");
        lean(0, -1);
        printf("%s\n", ans_s);
    }
    return 0;
}
