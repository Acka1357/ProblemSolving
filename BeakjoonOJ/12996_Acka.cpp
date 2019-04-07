//
// Created by Acka on 7/13/16.
//

#include <stdio.h>

#define MOD 1000000007

long long int d[51][51][51][51];

int main()
{
    int S, s[3]; scanf("%d %d %d %d", &S, &s[0], &s[1], &s[2]);

    d[0][0][0][0] = 1;
    for(int i = 1; i <= S; i++)
        for(int i1 = 0; i1 <= s[0]; i1++)
            for(int i2 = 0; i2 <= s[1]; i2++)
                for(int i3 = 0; i3 <= s[2]; i3++) {
                    if(i1) d[i][i1][i2][i3] += d[i - 1][i1 - 1][i2][i3];
                    if(i2) d[i][i1][i2][i3] += d[i - 1][i1][i2 - 1][i3];
                    if(i3) d[i][i1][i2][i3] += d[i - 1][i1][i2][i3 - 1];
                    if(i1 && i2) d[i][i1][i2][i3] += d[i - 1][i1 - 1][i2 - 1][i3];
                    if(i1 && i3) d[i][i1][i2][i3] += d[i - 1][i1 - 1][i2][i3 - 1];
                    if(i2 && i3) d[i][i1][i2][i3] += d[i - 1][i1][i2 - 1][i3 - 1];
                    if(i1 && i2 && i3) d[i][i1][i2][i3] += d[i - 1][i1 - 1][i2 - 1][i3 - 1];
                    d[i][i1][i2][i3] %= MOD;
                }

    printf("%lld\n", d[S][s[0]][s[1]][s[2]]);
    return 0;
}
