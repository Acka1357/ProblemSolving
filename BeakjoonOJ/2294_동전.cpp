//
// Created by Acka on 2017. 6. 12..
//

#include <stdio.h>

#define INF     987654321

bool chk[10001];
int N, K, c[100];
int d[10001];

int min(int x, int y){
    return x < y ? x : y;
}

int min_count(int k){
    if(chk[k]) return d[k];
    chk[k] = true;

    for(int i = 0; i < N; i++)
        if(k - c[i] >= 0)
            d[k] = min(d[k], min_count(k - c[i])) + 1;

    return d[k];
}

int main()
{
    scanf("%d %d", &N, &K);

    for(int i = 0; i < N; i++)
        scanf("%d", &c[i]);

    for(int i = 1; i <= K; i++)
        d[i] = INF;

    chk[0] = true;
    int ans = min_count(K);
    if(ans == INF) ans = -1;

    printf("%d\n", ans);
    return 0;
}
