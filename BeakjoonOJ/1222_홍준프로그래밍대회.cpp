//
// Created by Acka on 2017. 6. 16..
//

#include <stdio.h>
#include <algorithm>
using namespace std;

int cnt[2000001];

int main()
{
    int N; scanf("%d", &N);
    for(int i = 0, x; i < N; i++){
        scanf("%d", &x);
        cnt[x]++;
    }

    long long ans = 0;
    for(int i = 1; i <= 2000000; i++){
        int sum = 0;
        for(int j = i; j <= 2000000; j += i)
            sum += cnt[j];
        if(sum > 1) ans = max(ans, (long long)sum * i);
    }

    printf("%lld\n", ans);
    return 0;
}
