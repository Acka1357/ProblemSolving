//
// Created by Acka on 9/16/16.
//

#include <stdio.h>
#include <algorithm>
#include <memory.h>
using namespace std;

int due[3] = {1, 7, 30}, bus[3] = {3, 18, 45}, all[3] = {6, 36, 90};
int d[10031][30], cnt[10000][2];

int main()
{
    int tc; for(scanf("%d", &tc); tc--;){
        int N; scanf("%d", &N);

        for(int i = 0; i < N; i++) {
            scanf("%d %d", &cnt[i][0], &cnt[i][1]);
            cnt[i][1] <<= 1;
        }

        memset(d, 0x3f, (N + 31) * sizeof(d[0]));
        d[0][0] = 0;
        for(int i = 0; i < N; i++)
            for(int j = 0; j < 30; j++){
                if(j) d[i + 1][j - 1] = min(d[i + 1][j - 1], d[i][j] + cnt[i][1]);
                else d[i + 1][0] = min(d[i + 1][0], d[i][j] + cnt[i][0] + cnt[i][1]);

                for(int k = 0; k < 3; k++){
                    d[i + 1][due[k] - 1] = min(d[i + 1][due[k] - 1], d[i][j] + bus[k] + cnt[i][1]);
                    d[i + due[k]][0] = min(d[i + due[k]][0], d[i][j] + all[k]);
                    if(due[k] <= j) d[i + 1][j - due[k]] = min(d[i + 1][j - due[k]], d[i][j] + all[k]);
                }
            }

        int ans = d[N][0];
        for(int i = 0; i < 30; i++)
            for(int j = 0; j < 30; j++)
                ans = min(ans, d[N + i][j]);
        printf("%d\n", ans);
    }
    return 0;
}

