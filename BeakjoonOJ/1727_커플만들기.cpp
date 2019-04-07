//
// Created by Acka on 4/13/16.
//

#include <stdio.h>
#include <memory.h>
#include <algorithm>
using namespace std;

int absx(int x){ return x < 0 ? -x : x; }

int main()
{
    int N, M; scanf("%d %d", &N, &M);

    int n[1000], m[1000];
    if(N <= M){
        for(int i = 0; i < N; i++) scanf("%d", &n[i]);
        for(int i = 0; i < M; i++) scanf("%d", &m[i]);
    }
    else{
        for(int i = 0; i < N; i++) scanf("%d", &m[i]);
        for(int i = 0; i < M; i++) scanf("%d", &n[i]);
        N ^= M; M ^= N; N ^= M;
    }

    sort(n, n + N);
    sort(m, m + M);

    int d[1000][1000];
    memset(d, 0x3f, sizeof(d));
    d[0][0] = absx(n[0] - m[0]);
    for(int i = 1; i < N; i++)
        for(int j = i; j < M; j++)
            d[i][j] = min(d[i][j], min(d[i][j - 1], d[i - 1][j - 1] + absx(n[i] - m[j])));

    int ans = 0x3f3f3f3f;
    for(int i = N - 1; i < M; i++)
        ans = min(ans, d[N - 1][i]);

    printf("%d\n", ans);
    return 0;
}
