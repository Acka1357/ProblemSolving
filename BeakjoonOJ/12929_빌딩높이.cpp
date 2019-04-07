//
// Created by Acka on 7/7/16.
//

#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
    long long int N, K, M; scanf("%lld %lld %lld", &N, &K, &M);

    long long int x[502] = {1,}, t[502] = {0, };
    for(int i = 1; i <= M; i++)
        scanf("%lld", &x[i]);
    for(int i = 1; i <= M; i++)
        scanf("%lld", &t[i]);

    for (int i = 1; i <= M; i++)
        t[i] = min(t[i], t[i - 1] + K * (x[i] - x[i - 1]));
    for (int i = M - 1; 0 < i; i--)
        t[i] = min(t[i], t[i + 1] + K * (x[i + 1] - x[i]));

    long long int ans = 0;
    for(int i = 0; i < M; i++) {
        long long int m = ((x[i] + x[i + 1]) * K + t[i + 1] - t[i] + K) / (2 * K);
        ans = max(ans, min(t[i] + (m - x[i]) * K, t[i + 1] + (x[i + 1] - m) * K));
        printf("[(%lld, %lld), (%lld, %lld)]: %lld %lld %lld => %lld\n", x[i], t[i], x[i + 1], t[i + 1], m, t[i] + (m - x[i]) * K, t[i + 1] + (x[i + 1] - m) * K, min(t[i] + (m - x[i]) * K, t[i + 1] + (x[i + 1] - m) * K));
    }

    printf("%lld\n", max(ans, t[M] + (N - x[M]) * K));
    return 0;
}
