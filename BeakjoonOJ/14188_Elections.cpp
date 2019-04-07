//
// Created by Acka on 2017. 9. 11..
//

#include <stdio.h>
#include <memory.h>

int e[1000];
double p[1001], d[1001][2002];

int main()
{
    int N; while(scanf("%d", &N) == 1){
        if(N == 0) break;
        for(int i = 1; i <= N; i++)
            scanf("%lf %d", &p[i], &e[i]);

        memset(d, 0, (N + 1) * sizeof(d[0]));
        d[0][0] = 1;
        int sum = 0;
        for(int i = 1; i <= N; i++){
            for(int j = 0; j <= sum; j++){
                d[i][j + e[i]] += d[i - 1][j] * p[i];
                d[i][j] += d[i - 1][j] * (1 - p[i]);
            }
            sum += e[i];
        }

        double ans = 0;
        for(int i = (sum + 1) / 2; i <= sum; i++)
            ans += d[N][i];
        printf("%.4lf\n", ans);
    }
    return 0;
}
