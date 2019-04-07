//
// Created by Acka on 7/5/16.
//

#include <stdio.h>
#include <memory.h>
#include <queue>
using namespace std;

struct Crd{
    int c, r;
    Crd(){} Crd(int c, int r):c(c), r(r){}
};

int main()
{
    int dc[4] = {0, 1, 0 , -1}, dr[4] = {1, 0, -1, 0};
    int d[2][50]; memset(d, 0x3f, sizeof(d));

    char map[2][51];
    int C = 2, R; scanf("%d %s %s", &R, map[0], map[1]);

    int sum = 0;
    for(int i = 0; i < R; i++)
        sum += (map[0][i] == '.') + (map[1][i] == '.');

    queue<Crd> q;
    if(map[0][0] == '.') q.push(Crd(0, (d[0][0] = 0)));
    if(map[1][0] == '.') q.push(Crd(1, (d[1][0] = 0)));

    while(!q.empty()){
        int r = q.front().r, c = q.front().c, nr, nc;
        q.pop();

        for(int i = 0; i < 4; i++){
            nc = c + dc[i]; nr = r + dr[i];
            if(nc < 0 || nr < 0|| C <= nc || R <= nr) continue;
            if(map[nc][nr] == '.' && d[c][r] < d[nc][nr]){
                q.push(Crd(nc, nr));
                d[nc][nr] = d[c][r] + 1;
            }
        }
    }

    printf("%d\n", sum - 1 - min(d[0][R - 1], d[1][R - 1]));
    return 0;
}
