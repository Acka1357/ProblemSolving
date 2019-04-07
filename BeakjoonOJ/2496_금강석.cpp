//
// Created by Acka on 7/22/16.
//

#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
    int N, M, T, K; scanf("%d %d %d %d", &N, &M, &T, &K);

    int crd[700][2];
    for(int i = 0; i < T; i++) {
        scanf("%d %d", &crd[i][0], &crd[i][1]);
        crd[2 * T + i][0] = crd[4 * T + i][0] = crd[i][0];
        crd[1 * T + i][0] = crd[5 * T + i][0] = crd[i][0] + 1;
        crd[3 * T + i][0] = crd[6 * T + i][0] = crd[i][0] - 1;
        crd[1 * T + i][1] = crd[3 * T + i][1] = crd[i][1];
        crd[2 * T + i][1] = crd[6 * T + i][1] = crd[i][1] + 1;
        crd[4 * T + i][1] = crd[5 * T + i][1] = crd[i][1] - 1;
    }

    int ans = 0, ansx, ansy, sum_lb, sum_ub, sub_lb, sub_ub;
    for(int i = 0; i < 7 * T; i++)
        for(int j = 0; j < 7 * T; j++){
            sum_lb = crd[i][0] + crd[i][1];
            sum_ub = sum_lb + K;
            sub_ub = crd[j][1] - crd[j][0];
            sub_lb = sub_ub - K;
            if((sum_lb - sub_ub) & 1) continue;

            int cnt = 0;
            for(int k = 0; k < T; k++)
                if(sum_lb <= crd[k][0] + crd[k][1] && crd[k][0] + crd[k][1] <= sum_ub &&
                        sub_lb <= crd[k][1] - crd[k][0] && crd[k][1] - crd[k][0] <= sub_ub){
                    cnt++;
                }

            if(ans < cnt){
                ans = cnt;
                ansx = (sum_lb - sub_ub + K) / 2;
                ansy = (sum_lb + sub_ub) / 2;
            }
        }


    printf("%d %d\n%d\n", ansx, ansy, ans);
    return 0;
}

