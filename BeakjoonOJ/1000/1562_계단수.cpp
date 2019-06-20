//
// Created by Acka on 2017. 5. 25..
//

#include <stdio.h>
#include <memory.h>

#define MOD	1000000000

int d[101][10][1024], bit[10] = {1,};

int main()
{
    int N; scanf("%d", &N);

	for (int i = 1; i <= 9; i++) {
        d[1][i][(1 << i)] = 1;
        bit[i] = bit[i - 1] << 1;
    }

    for(int i = 1; i < N; i++)
        for(int j = 0; j <= 9; j++)
            for(int used = 2; used <= 1023; used++){
                if(j) d[i + 1][j - 1][used | bit[j - 1]] =
                      (d[i + 1][j - 1][used | bit[j - 1]] + d[i][j][used]) % MOD;
                if(j < 9) d[i + 1][j + 1][used | bit[j + 1]] =
                      (d[i + 1][j + 1][used | bit[j + 1]] + d[i][j][used]) % MOD;
            }

    int ans = 0;
    for(int i = 0; i <= 9; i++)
        ans = (ans + d[N][i][1023]);

    printf("%d\n", ans);
	return 0;
}
