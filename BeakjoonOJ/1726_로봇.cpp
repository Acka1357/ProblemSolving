//
// Created by Acka on 4/14/16.
//

#include <stdio.h>
#include <memory.h>
#include <queue>
using namespace std;

struct Info{
    int r, c, d;
    Info(){} Info(int r, int c, int d):r(r), c(c), d(d){}
};

int main()
{
    int dir[2][4] = {{3, 2, 0, 1}, {2, 3, 1, 0}};   //0: left, 1: right
    int ar[4] = {0, 0, 1, -1}, ac[4] = {1, -1, 0, 0};

    int R, C; scanf("%d %d", &R, &C);
    int map[100][100];
    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++)
            scanf("%d", &map[i][j]);

    int sr, sc, sd, er, ec, ed;
    scanf("%d %d %d %d %d %d", &sr, &sc, &sd, &er, &ec, &ed);
    sr--; sc--; sd--; er--; ec--; ed--;

    int d[100][100][4];
    memset(d, 0xff, sizeof(d));

    queue<Info> q;
    q.push(Info(sr, sc, sd)); d[sr][sc][sd] = 0;

    int cr, cc, cd, nr, nc, nd;
    while(!q.empty()){
        cr = q.front().r; cc = q.front().c; cd = q.front().d;
        q.pop();

        if(cr == er && cc == ec && cd == ed) break;

        for(int i = 1; i <= 3; i++){
            nr = cr + i * ar[cd]; nc = cc + i * ac[cd];
            if(nr < 0 || nc < 0 || R <= nr || C <= nc) break;
            if(map[nr][nc]) break;
            if(d[nr][nc][cd] == -1){
                d[nr][nc][cd] = d[cr][cc][cd] + 1;
                q.push(Info(nr, nc, cd));
            }
        }

        for(int i = 0; i < 2; i++){
            nd = dir[i][cd];
            if(d[cr][cc][nd] == -1){
                d[cr][cc][nd] = d[cr][cc][cd] + 1;
                q.push(Info(cr, cc, nd));
            }
        }
    }

    printf("%d\n", d[er][ec][ed]);
    return 0;
}
