//
// Created by Acka on 7/4/16.
//

#include <stdio.h>
#include <memory.h>
#include <algorithm>
using namespace std;

int d[61][61][61], N, o[3];

int get_min_shot(int r1, int r2, int r3){
    if(r1 < 0) r1 = 0;
    if(r2 < 0) r2 = 0;
    if(r3 < 0) r3 = 0;
    if(0 <= d[r1][r2][r3]) return d[r1][r2][r3];

    d[r1][r2][r3] = get_min_shot(r1 - 9, r2 - 3, r3 - 1);
    d[r1][r2][r3] = min(d[r1][r2][r3], get_min_shot(r1 - 9, r2 - 1, r3 - 3));
    d[r1][r2][r3] = min(d[r1][r2][r3], get_min_shot(r1 - 3, r2 - 9, r3 - 1));
    d[r1][r2][r3] = min(d[r1][r2][r3], get_min_shot(r1 - 3, r2 - 1, r3 - 9));
    d[r1][r2][r3] = min(d[r1][r2][r3], get_min_shot(r1 - 1, r2 - 9, r3 - 3));
    d[r1][r2][r3] = min(d[r1][r2][r3], get_min_shot(r1 - 1, r2 - 3, r3 - 9));

    return d[r1][r2][r3] = d[r1][r2][r3] + 1;
}

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", &o[i]);

    memset(d, 0xff, sizeof(d));

    d[0][0][0] = 0;
    printf("%d\n", get_min_shot(o[0], o[1], o[2]));

    return 0;
}
