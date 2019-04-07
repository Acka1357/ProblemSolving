//
// Created by Acka on 4/16/16.
//

#include <stdio.h>

int main()
{
    int N, S, M; scanf("%d %d %d", &N, &S, &M);

    int v[100];
    for(int i = 0; i < N; i++)
        scanf("%d", &v[i]);

    bool psb[101][1001] = {false,};
    psb[0][S] = true;
    for(int i = 0; i < N; i++)
        for(int j = 0; j <= M; j++)
            if(psb[i][j]){
                if(j + v[i] <= M) psb[i + 1][j + v[i]] = true;
                if(0 <= j - v[i]) psb[i + 1][j - v[i]] = true;
            }

    int ans = -1;
    for(int i = M; 0 <= i; i--)
        if(psb[N][i]){
            ans = i; break;
        }

    printf("%d\n", ans);
    return 0;
}
