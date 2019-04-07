//
// Created by Acka on 2017. 4. 15..
//

#include <stdio.h>
#include <algorithm>
#include <queue>
#include <assert.h>
using namespace std;

int need[50], cnt[50][50];

int main()
{
    freopen("/Users/Acka/ClionProjects/ProblemSolving/Codejam/17_Round1A/B-large.in", "r", stdin);
    freopen("/Users/Acka/ClionProjects/ProblemSolving/Codejam/17_Round1A/B-large.out", "w", stdout);

    int T, tc = 0; for(scanf("%d", &T); tc++ < T;){
        int N, P; scanf("%d %d", &N, &P);

        queue<int> q[50];
        for(int i = 0; i < N; i++)
            scanf("%d", &need[i]);
        for(int i = 0; i < N; i++) {
            for (int j = 0; j < P; j++)
                scanf("%d", &cnt[i][j]);

            sort(cnt[i], cnt[i] + P);
            for(int j = 0; j < P; j++)
                q[i].push(cnt[i][j]);
        }

        int ans = 0;
        while(true){
            bool rem = true;
            for(int i = 0; i < N; i++)
                if(q[i].empty()) rem = false;
            if(!rem) break;

            int l = 0, r = 987654321;
            for(int i = 0; i < N; i++){
                l = max(l, ((q[i].front() * 10) + 11 * need[i] - 1) / (need[i] * 11));
                r = min(r, (q[i].front() * 10) / (need[i] * 9));
            }

            if(0 < l && l <= r){
                ans++;
                for(int i = 0; i < N; i++)
                    q[i].pop();
            }
            else{
                for(int i = 0; i < N; i++)
                    if(r == (q[i].front() * 10) / (need[i] * 9))
                        q[i].pop();
            }
        }

        printf("Case #%d: %d\n", tc, ans);
    }
    return 0;
}

