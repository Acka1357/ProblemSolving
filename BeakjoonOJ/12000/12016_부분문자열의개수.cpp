//
// Created by Acka on 2017. 10. 19..
//

#include <stdio.h>
#include <string.h>

#define MOD     1000000009

long long d[101][101][2];
char s[102];

int main()
{
    int L; scanf("%d %s", &L, s + 1);
    int sl = strlen(s + 1);

    d[0][0][0] = 1;
    for(int i = 1; i <= L; i++){
        d[i][0][1] = (25 * d[i - 1][sl][1]) % MOD;
        d[i][1][1] = d[i - 1][sl][1] % MOD;
        for(int j = 0; j < sl; j++)
            for(int k = 0; k < 2; k++){
                d[i - 1][j][k] %= MOD;
                d[i][j + 1][k] += d[i - 1][j][k];
                if(s[j + 1] == s[1])
                    d[i][0][k] += 25 * d[i - 1][j][k];
                else{
                    d[i][0][k] += 24 * d[i - 1][j][k];
                    d[i][1][k] += d[i - 1][j][k];
                }
            }
        d[i][sl][1] += d[i - 1][sl - 1][0];
    }

    long long ans = 0;
    for(int i = 0; i <= sl; i++)
        ans += d[L][i][1];
    printf("%lld\n", ans % MOD);

    return 0;
}
