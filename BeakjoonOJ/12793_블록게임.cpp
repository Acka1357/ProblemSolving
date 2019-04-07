//
// Created by Acka on 2016. 11. 14..
//

#include <stdio.h>
#include <queue>
using namespace std;

struct Crd{
    int r, c;
    Crd(){} Crd(int r, int c):r(r), c(c){}
};

int dr[4] = {0, 1, 0, -1}, dc[4] = {1, 0, -1, 0};
int top_r, btm_r, left_c, right_c;
char map[201][202];

void remove_cell(int sr, int sc){
    queue<Crd> q; q.push(Crd(sr, sc));
    map[sr][sc] = 'O';
    while(!q.empty()){
        int r = q.front().r, c = q.front().c; q.pop();
        for(int i = 0; i < 4; i++){
            int nr = r + dr[i], nc = c + dc[i];
            if(map[nr][nc] != '.') continue;

            nr += dr[i]; nc += dc[i];
            if(map[nr][nc] == 'B') {
                map[nr][nc] = 'O';
                q.push(Crd(nr, nc));
            }
        }
    }
}

int main()
{
    double st;
    int N, M; scanf("%d %d %lf", &M, &N, &st);
    top_r = left_c = 0; btm_r = 2 * N; right_c = 2 * M;

    for(int i = 0; i <= 2 * N; i++)
        scanf("%s", map[i]);

    int r = btm_r, c = st * 2 + 0.1, ar, ac, add_r = -1, add_c = -1, ans = 0;
    while(true){
        ar = (2 * r + add_r - 1) / 2; ac = (2 * c + add_c - 1) / 2;

        r += add_r; c += add_c;
        if(r == btm_r) break;
        else {
            if(r == top_r) add_r *= -1;
            if(c == left_c || c == right_c) add_c *= -1;
        }

        for(int i = 0; i < 2; i++)
            for(int j = 0; j < 2; j++)
                if((ar + i) & 1 && (ac + j) & 1){
                    if(map[ar + i][ac + j] == 'B'){
                        remove_cell(ar + i, ac + j);
                        ans++;
                    }
                }
    }

    printf("%d\n", ans);
    return 0;
}
