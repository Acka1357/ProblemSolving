//
// Created by Acka on 2017. 10. 10..
//

#include <stdio.h>
#include <algorithm>
using namespace std;

double maxs[101], x;

int main()
{
    int N, M, K; scanf("%d %d %d", &N, &M, &K);
    for(int i = 0, n; i < M; i++)
        for(int j = 0; j < N; j++){
            scanf("%d %lf", &n, &x);
            maxs[n] = max(maxs[n], x);
        }

    sort(maxs + 1, maxs + N + 1);

    double ans = 0;
    for(int i = N - K + 1; i <= N; i++)
        ans += maxs[i];

    printf("%.1lf\n", ans);
    return 0;
}
