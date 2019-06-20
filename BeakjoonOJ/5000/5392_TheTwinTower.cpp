//
// Created by Acka on 9/10/16.
//

#include <stdio.h>

#define MOD 10007

int d[9 * 5000 + 1][(1 << 9)];

int main()
{
    d[0][0] = 1;
    int all = (1 << 9) - 1, tile = 9 * 5000, nst = (1 << 8);
    for(int i = 0; i < tile; i++) {
        for(int st = 0; st <= all; st++)
            d[i][st] %= MOD;

        for (int st = 0; st <= all; st++) {
            int cur = i % 9;
            if(st & 1) d[i + 1][(st >> 1)] += d[i][st];
            else {
                if(!(st & 3) && (cur % 3 != 2))
                    d[i + 2][(st >> 2)] += d[i][st];
                if(!(st & 9) && (cur / 3 != 2))
                    d[i + 1][(st >> 1) + 4] += d[i][st];
                d[i + 1][(st >> 1) + nst] += d[i][st];
            }
        }
    }

    int tc; for(scanf("%d", &tc); tc--;){
        int N; scanf("%d", &N);
        printf("%d\n", d[9 * N][0] % MOD);
    }
    return 0;
}

