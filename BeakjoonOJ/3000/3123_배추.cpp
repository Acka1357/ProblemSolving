//
// Created by Acka on 2017. 7. 10..
//

#include <stdio.h>
#include <math.h>

const double PI = acos(-1.0);

double area[1 << 4];
int stat[1001][1001];

int main()
{
    int R, C, N; scanf("%d %d %d", &R, &C, &N);

    for(int i = 0, r, c; i < N; i++){
        scanf("%d %d", &r, &c);
        stat[r][c] |= 1;
        if(r) stat[r - 1][c] |= 4;
        if(c) stat[r][c - 1] |= 2;
        if(r && c) stat[r - 1][c - 1] |= 8;
    }

    for(int i = 1; i < 16; i++) area[i] = 1;
    area[1] = area[2] = area[4] = area[8] = PI / 4;
    area[3] = area[12] = area[5] = area[10] = PI / 6 + sqrt(3) / 4;

    double ans = 0;
    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++)
            ans += area[stat[i][j]];

    printf("%.10lf\n", ans);
    return 0;
}
