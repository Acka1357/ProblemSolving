//
// Created by Acka on 4/20/16.
//

#include <stdio.h>
#include <memory.h>
#include <algorithm>
using namespace std;

int main()
{
    int N; scanf("%d", &N);

    int org[103] = {0,}, ans[103] = {0,};
    for(int i = 1; i <= N; i++)
        scanf("%1d", &org[i + 1]);
    for(int i = 1; i <= N; i++)
        scanf("%1d", &ans[i + 1]);

    int d[103][1000], j1, j2, d1, d2, d3, x;
    memset(d, 0x3f, sizeof(d));

    d[1][org[2]] = 0;
    for(int k = -3; k <= 3; k++)
        if(k) d[1][((org[2] + k + 10) % 10)] = 1;
    for(int k = 4; k <= 6; k++)
        d[1][((org[2] + k + 10) % 10)] = 2;

    for(int i = 2; i <= N; i++) {
        for (int j = 0; j < 100; j++) {
            d[i][j1 = (j * 10 + org[i + 1])] = d[i - 1][ans[i - 2] * 100 + j];
            for(int k = -3; k <= 3; k++)
                if(k) d[i][(j * 10) + ((org[i + 1] + k + 10) % 10)] = d[i][j1] + 1;
            for(int k = 4; k <= 6; k++)
                d[i][(j * 10) + ((org[i + 1] + k) % 10)] = d[i][j1] + 2;
        }

        for(int j = 0; j < 100; j++)
            for(d1 = 0; d1 < 10; d1++) {
                d2 = j / 10; d3 = j % 10; j1 = 100 * d1 + j;
                for (int k = -3; k <= 3; k++)
                    if (k) {
                        x = d1 * 100 + (((d2 + k + 10) % 10) * 10) + (((d3 + k + 10)) % 10);
                        d[i][x] = min(d[i][x], d[i][j1] + 1);
                    }
                for (int k = 4; k <= 6; k++) {
                    x = d1 * 100 + (((d2 + k) % 10) * 10) + (((d3 + k + 10)) % 10);
                    d[i][x] = min(d[i][x], d[i][j1] + 2);
                }
            }

        for(int j = 0; j < 1000; j++){
            d1 = j / 100; d2 = (j / 10) % 10; d3 = j % 10;
            for(int k = -3; k <= 3; k++)
                if(k){
                    x = ((d1 + k + 10) % 10) * 100 + (((d2 + k + 10) % 10) * 10) + (((d3 + k + 10)) % 10);
                    d[i][x] = min(d[i][x], d[i][j] + 1);
                }
            for(int k = 4; k <= 6; k++){
                x = ((d1 + k + 10) % 10)* 100 + (((d2 + k) % 10) * 10) + (((d3 + k + 10)) % 10);
                d[i][x] = min(d[i][x], d[i][j] + 2);
            }
        }
    }

    printf("%d\n", d[N][ans[N - 1] * 100 + ans[N] * 10 + ans[N + 1]]);
    return 0;
}
