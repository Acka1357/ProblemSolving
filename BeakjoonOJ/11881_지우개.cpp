//
// Created by Acka on 4/11/16.
//

#include <stdio.h>
#include <algorithm>
using namespace std;

#define MOD 1000000007

int main()
{
    int N; scanf("%d", &N);

    int n[100000];
    for(int i = 0; i < N; i++)
        scanf("%d", &n[i]);

    sort(n, n + N);

    int cnt[100001] = {0,};
    long long int l = 0, m = 0, r = 0, ans = 0;
    for(int i = 0; i < N; i++) {
        cnt[n[i]]++;
        r += n[i];
    }

    for(int i = 1; i <= 100000; i++)
        if(cnt[i]){
            l += m; m = i * cnt[i]; r -= m;
            ans = (ans + ((((l % MOD) * (m % MOD)) % MOD) * (r % MOD))) % MOD;
        }

    printf("%lld\n", ans);
    return 0;
}
