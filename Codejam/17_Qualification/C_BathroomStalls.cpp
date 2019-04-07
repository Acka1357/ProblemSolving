//
// Created by Acka on 2017. 4. 8..
//

#include <stdio.h>
#include <queue>
#include <map>
using namespace std;

int main()
{
    freopen("/Users/Acka/ClionProjects/ProblemSolving/Codejam/17_Qualification/C-large.in", "r", stdin);
    freopen("/Users/Acka/ClionProjects/ProblemSolving/Codejam/17_Qualification/C_large.out", "w", stdout);

    int T, tc = 0; for(scanf("%d", &T); tc++ < T;){
        long long N, K; scanf("%lld %lld", &N, &K);

        priority_queue<long long> q;
        map<long long, long long> m;

        q.push(N);
        m[N] = 1;
        long long ansl, ansr;
        while(0 <= K){
            long long cl = q.top(); q.pop();
            long long cnt = m[cl];

            ansl = (cl / 2) - 1 + (cl & 1);
            ansr = (cl / 2);

            if(K <= cnt) break;
            else{
                K -= cnt;
                if(m.count(ansl)){
                    m[ansl] += cnt;
                    if(m.count(ansr)) m[ansr] += cnt;
                    else {
                        q.push(ansr);
                        m[ansr] = cnt;
                    }
                }
                else{
                    q.push(ansl);
                    m[ansl] = cnt;
                    if(m.count(ansr)) m[ansr] += cnt;
                    else{
                        q.push(ansr);
                        m[ansr] = cnt;
                    }
                }
            }
        }

        printf("Case #%d: %lld %lld\n", tc, ansr, ansl);
    }
    return 0;
}

