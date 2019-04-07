//
// Created by Acka on 2017. 9. 3..
//

#include <stdio.h>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    long long x;
    int tc; for(scanf("%d", &tc); tc--;){
        int N; scanf("%d", &N);

        long long ans = 0, cur, gcd, newl;
        map<long long, long long> len;
        queue<long long> q;
        q.push(1);
        for(int i = 1; i <= N; i++){
            scanf("%lld", &x);
            set<long long> chk;
            for(int j = q.size(); j > 0; j--){
                cur = q.front(); q.pop();
                gcd = __gcd(x, cur);
                newl = len[cur] + 1;
                if(chk.count(gcd)){
                    len[gcd] = max(len[gcd], newl);
                }
                else{
                    chk.insert(gcd);
                    len[gcd] = newl;
                    q.push(gcd);
                }
                ans = max(ans, gcd * newl);
            }
            if(!chk.count(x)){
                ans = max(ans, x);
                len[x] = 1;
                q.push(x);
            }
        }

        printf("%lld\n", ans);
    }
    return 0;
}
