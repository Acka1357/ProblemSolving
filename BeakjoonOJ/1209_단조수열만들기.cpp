//
// Created by Acka on 4/12/16.
//

#include <stdio.h>
#include <memory.h>
#include <algorithm>
using namespace std;

#define ABS(x)  (x < 0 ? (-(x)) : (x))

long long int d[2000][2000];

int main()
{
    int N, n[2000], s[2000]; scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        scanf("%d", &n[i]);
        s[i] = n[i];
    }

    sort(s, s + N);

    memset(d, 0x3f, sizeof(d));
    for(int i = 0; i < N; i++)
        d[0][i] = ABS(n[i] - s[0]);

    for(int i = 1; i < N; i++){
        d[i][0] = d[i - 1][0] + ABS(n[i] - s[0]);
        for(int j = 1; j < N; j++)
            d[i][j] = min(d[i][j - 1] + ABS(n[i] - s[j - 1]), d[i - 1][j] + ABS(n[i] - s[j]));
    }

    long long int ans = 1ll << 62;
    for(int i = 0; i < N; i++)
        ans = min(ans, d[N - 1][i]);

    memset(d, 0x3f, sizeof(d));
    for(int i = 0; i < N; i++)
        d[0][i] = ABS(n[i] - s[N - 1]);

    for(int i = 1; i < N; i++){
        d[i][N - 1] = d[i - 1][N - 1] + ABS(n[i] - s[N - 1]);
        for(int j = N - 2; 0 <= j; j--)
            d[i][j] = min(d[i][j + 1] + ABS(n[i] - s[j + 1]), d[i - 1][j] + ABS(n[i] - s[j]));
    }

    for(int i = 0; i < N; i++)
        ans = min(ans, d[N - 1][i]);

    printf("%lld\n", ans);
    return 0;
}
