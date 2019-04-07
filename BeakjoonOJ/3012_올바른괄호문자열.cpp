//
// Created by Acka on 2017. 7. 10..
//

#include <stdio.h>

#define MOD     100000

char s[201];
int d[200][200], cases[128][128];

int mod(long long x){
    return x >= MOD ? MOD + (x % MOD) : x;
}

int main()
{
    cases['('][')'] = cases['['][']'] = cases['{']['}'] = 1;
    cases['?'][')'] = cases['?'][']'] = cases['?']['}'] = 1;
    cases['(']['?'] = cases['[']['?'] = cases['{']['?'] = 1;
    cases['?']['?'] = 3;

    int len; scanf("%d %s", &len, s);
    for(int i = 1; i <= len; i++)
        d[i][i - 1] = 1;

    for(int size = 2; size <= len; size += 2)
        for(int r = size - 1; r < len; r++){
            int l = r - size + 1;
            for(int m = l + 1; m <= r; m += 2)
                d[l][r] += mod((long long)d[l + 1][m - 1] * d[m + 1][r] * cases[s[l]][s[m]]);
            d[l][r] = mod(d[l][r]);
        }

    if(d[0][len - 1] >= MOD) printf("%05d\n", d[0][len - 1] % MOD);
    else printf("%d\n", d[0][len - 1]);
    return 0;
}

