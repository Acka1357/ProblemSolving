//
// Created by Acka on 2017. 3. 31..
//

#include <stdio.h>

double d[100][10];

int main()
{
    int K, N;
    while(scanf("%d %d", &K, &N) == 2){
        for(int i = 0; i <= K; i++)
            d[0][i] = 100.0 / (K + 1);

        double p = 1.0 / (K + 1);
        for(int i = 1; i < N; i++){
            for(int j = 0; j <= K; j++)
                d[i][j] = 0;
            for(int j = 0; j <= K; j++){
                if(j) d[i][j - 1] += d[i - 1][j] * p;
                d[i][j] += d[i - 1][j] * p;
                if(j < K) d[i][j + 1] += d[i - 1][j] * p;
            }
        }

        double ans = 0;
        for(int i = 0; i <= K; i++)
            ans += d[N - 1][i];
        printf("%.5lf\n", ans);
    }
    return 0;
}
