//
// Created by Acka on 7/5/16.
//

#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
    int N, D; scanf("%d %d", &N, &D);

    char c; int d[50][50];
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++){
            scanf(" %c", &c);
            d[i][j] = (c == 'Y' ? 1 : -1);
        }

    for(int k = 0; k < N; k++)
        for(int i = 0; i < N; i++) {
            if(d[i][k] < 0) continue;
            for (int j = 0; j < N; j++) {
                if(d[k][j] < 0) continue;
                if (d[i][j] < 0) d[i][j] = d[i][k] + d[k][j];
                else d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }

    int ans = 0;
    for(int i = 0; i < N; i++) {
        int h = 0;
        for (int j = 0; j < N; j++) {
            if(i == j) continue;
            if(d[i][j] < 0){ ans = -1; break; }
            h = max(h, d[i][j]);
        }
        if(ans < 0) break;
        ans = max(ans, h);
    }

    printf("%d\n", ans < 0 ? ans : (ans * D));
    return 0;
}

