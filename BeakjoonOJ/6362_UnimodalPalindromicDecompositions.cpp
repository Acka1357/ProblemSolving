//
// Created by Acka on 4/23/16.
//

#include <stdio.h>

long long int d[301][301];

int main()
{
    d[0][0] = 1;
    for(int i = 1; i <= 300; i++)
        for(int j = 1; j <= i; j++)
            for(int k = j; 0 <= k; k--)
                d[i][j] += d[i - j][k];

    int x;
    while(scanf("%d", &x) == 1){
        if(!x) break;

        long long int sum = 0;
        for(int i = 1; i <= x; i++)
            if(!((x - i) & 1)){
                for(int j = 0; j <= i; j++)
                    sum += d[(x - i) / 2][j];
            }

        if(!(x & 1)) {
            for (int i = x / 2; 1 <= i; i--)
                sum += d[x / 2][i];
        }

        printf("%d %lld\n", x, sum);
    }
    return 0;
}
