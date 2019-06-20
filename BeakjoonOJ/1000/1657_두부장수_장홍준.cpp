//
// Created by Acka on 9/29/16.
//

#include <stdio.h>
#include <algorithm>
using namespace std;

char map[15][15];
int N, M, d[15 * 14][1 << 14], ci[256];
int cost[5][5] = {{10, 8, 7, 5, 1},
                  {8, 6, 4, 3, 1},
                  {7, 4, 3, 2, 1},
                  {5, 3, 2, 2, 1},
                  {1, 1, 1, 1, 0}};

int main()
{
    ci['A'] = 0; ci['B'] = 1; ci['C'] = 2; ci['D'] = 3; ci['F'] = 4;

    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++)
        scanf("%s", map[i]);

    int cnt = N * M, all = 1 << M, last = 1 << (M - 1);
    for(int i = 0, r = 0, c = 0, nr = 0, nc = 1; i < cnt; i++, nc++) {
        nr += nc / M; nc %= M;
        for (int stat = 0; stat < all; stat++) {
            d[i + 1][stat >> 1] = max(d[i + 1][stat >> 1], d[i][stat]);
            if(!(stat & 1)) d[i + 1][(stat >> 1) + last] = max(d[i + 1][(stat >> 1) + last], d[i][stat] + cost[ci[map[r][c]]][ci[map[r + 1][c]]]);
            if(!(stat & 3) && nc) d[i + 1][(stat >> 1) + 1] = max(d[i + 1][(stat >> 1) + 1], d[i][stat] + cost[ci[map[r][c]]][ci[map[nr][nc]]]);
        }
        r = nr; c = nc;
    }

    printf("%d\n", d[cnt][0]);
    return 0;
}
