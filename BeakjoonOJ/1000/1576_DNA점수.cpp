//
// Created by Acka on 2016. 12. 24..
//

#include <stdio.h>
#include <memory.h>
#include <algorithm>
using namespace std;

#define O       160

int idx[256][256], cnt[10], x[10], y[10], d[11][16 * 21 + 1];
char s[100][101], sq[5] = "ACGT";

int main()
{
    int N; scanf("%d", &N);
    for(int i = 0, ii = 0; i < 4; i++)
        for(int j = i; j < 4; j++) {
            x[ii] = i; y[ii] = j;
            idx[sq[i]][sq[j]] = idx[sq[j]][sq[i]] = ii++;
        }

    for(int i = 0; i < N; i++)
        scanf("%s", s[i]);

    for(int i = 0; i < N; i++)
        for(int j = i + 1; j < N; j++)
            for(int k = 0; s[i][k]; k++){
                if(s[i][k] < s[j][k]) cnt[idx[s[i][k]][s[j][k]]]++;
                else cnt[idx[s[j][k]][s[i][k]]]++;
            }

    memset(d, 0x80, sizeof(d));
    int pcnt = 0;
    d[0][O] = 0;
    for(int i = 0; i < 10; i++) {
        int dup = 1 + (x[i] != y[i]);
        for (int j = -10 * pcnt + O, jm = 10 * pcnt + O; j <= jm; j++)
            for(int k = (1 < dup ? -10 : 1); k <= 10; k++)
                d[i + 1][j + k * dup] = max(d[i + 1][j + k * dup], d[i][j] + cnt[i] * k);
        pcnt += dup;
    }

    printf("%.2lf\n", (d[10][O] << 1) / (N * (N - 1.0)));
    return 0;
}

