//
// Created by Acka on 9/26/16.
//

#include <stdio.h>
#include <memory.h>
#include <algorithm>
using namespace std;

long long int cost[100][100], dp[100][100][100];

int main()
{
    int tc; for (scanf("%d", &tc); tc--;){
        int N, M; scanf("%d %d", &N, &M);

        int s1, s2, s3, t1, t2, t3;
        scanf("%d %d %d %d %d %d", &s1, &s2, &s3, &t1, &t2, &t3);
        s1--; s2--; s3--; t1--; t2--; t3--;

        memset(cost, 0x00, N * sizeof(cost[0]));
        memset(dp, 0xff, N * sizeof(dp[0]));
        for (int i = 0, u, v, c; i < M; i++){
            scanf("%d %d %d", &u, &v, &c);
            cost[u - 1][v - 1] = c;
        }

        dp[s1][s2][s3] = 0;
        for (int t = min(s1, min(s2, s3)) + 1, last = max(t1, max(t2, t3)), bgt = max(s1, max(s2, s3)); t <= last; t++)
            for (int i = s1, im = min(t1, max(t - 1, bgt)); i <= im; i++)
                for (int j = s2, jm = min(t2, max(t - 1, bgt)); j <= jm; j++){
                    if(i == j) continue;
                    for (int k = s3, km = min(t3, max(t - 1, bgt)); k <= km; k++){
                        if (dp[i][j][k] < 0 || j == k || i == k) continue;
                        if (cost[i][t]) dp[t][j][k] = max(dp[t][j][k], dp[i][j][k] + cost[i][t]);
                        if (cost[j][t]) dp[i][t][k] = max(dp[i][t][k], dp[i][j][k] + cost[j][t]);
                        if (cost[k][t]) dp[i][j][t] = max(dp[i][j][t], dp[i][j][k] + cost[k][t]);
                    }
                }

        printf("%lld\n", dp[t1][t2][t3] <= 0 ? 0 : dp[t1][t2][t3]);
    }
    return 0;
}
