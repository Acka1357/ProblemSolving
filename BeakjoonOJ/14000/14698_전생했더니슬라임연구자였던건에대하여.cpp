//
// Created by Acka on 2017. 9. 14..
//

#include <stdio.h>
#include <queue>
#include <functional>
using namespace std;

#define MOD     1000000007

int main()
{
    int tc; for(scanf("%d", &tc); tc--;){
        int N; scanf("%d", &N);

        priority_queue<long long, vector<long long>, greater<long long>> q;
        long long x;
        for(int i = 0; i < N; i++){
            scanf("%lld", &x);
            q.push(x);
        }

        long long ans = 1, a, b;
        while(q.size() > 1){
            a = q.top(); q.pop();
            b = q.top(); q.pop();
            q.push(a * b);
            ans = (ans * (((a % MOD) * (b % MOD)) % MOD)) % MOD;
        }

        printf("%lld\n", ans);
    }
    return 0;
}
