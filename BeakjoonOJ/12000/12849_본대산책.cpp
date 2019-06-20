//
// Created by Acka on 2017. 2. 17..
//

#include <stdio.h>

#define MOD     1000000007

bool path[8][8] = {
        0, 1, 1, 0, 0, 0, 0, 0,
        1, 0, 1, 1, 0, 0, 0, 0,
        1, 1, 0, 1, 1, 0, 0, 0,
        0, 1, 1, 0, 1, 1, 0, 0,
        0, 0, 1, 1, 0, 1, 0, 1,
        0, 0, 0, 1, 1, 0, 1, 0,
        0, 0, 0, 0, 0, 1, 0, 1,
        0, 0, 0, 0, 1, 0, 1, 0
};

long long int d[2][8];

int main()
{
    int N; scanf("%d", &N);

    int t = 0;
    d[t][0] = 1;
    while(N--){
        for(int i = 0; i < 8; i++){
            d[!t][i] = 0;
            for(int j = 0; j < 8; j++)
                if(path[j][i]) d[!t][i] += d[t][j];
            d[!t][i] %= MOD;
        }
        t = !t;
    }

    printf("%lld\n", d[t][0]);
    return 0;
}
