//
// Created by Acka on 2017. 1. 24..
//

#include <stdio.h>
#include <memory.h>
#include <algorithm>
using namespace std;

int N, d[1000][1000][2], a[1000];

int get_val(int i, int j, int k){
    if(j < 0 || N <= j) return 0;
    return d[i][j][k];
}

int main()
{
    int tc; for(scanf("%d", &tc); tc--;){
        scanf("%d", &N);
        for(int i = 0; i < N; i++)
            scanf("%d", &a[i]);

        d[0][0][0] = a[0];
        d[0][N - 1][0] = a[N - 1];
        d[0][0][1] = d[0][N - 1][1] = 0;
        for(int i = 1, t = 1; i < N; i++, t = !t){
            for(int j = 0; j < i; j++){
                d[i][j][!t] = max(get_val(i - 1, j - 1, !t), get_val(i - 1, N - i + j, !t));
                d[i][j][t] = max(get_val(i - 1, j - 1, t), get_val(i - 1, N - i + j, t)) + a[j];
                printf("%d %d: %d %d\n", i, j, d[i][j][0], d[i][j][1]);
            }
            for(int j = N - i; j < N; j++){
                d[i][j][!t] = max(get_val(i - 1, i - N + j, !t), get_val(i - 1, j + 1, !t));
                d[i][j][t] = max(get_val(i - 1, i - N + j, t), get_val(i - 1, j + 1, t)) + a[j];
                printf("%d %d: %d %d\n", i, j, d[i][j][0], d[i][j][1]);
            }
        }

        int ans = 0;
        for(int i = 0; i < N; i++) {
            printf("%d %d\n", i, d[N - 1][i][0]);
            ans = max(ans, d[N - 1][i][0]);
        }
        printf("%d\n", ans);
    }
    return 0;
}
