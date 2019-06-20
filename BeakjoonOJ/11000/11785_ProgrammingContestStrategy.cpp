//
// Created by Acka on 7/19/16.
//

#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
    int tc, st = 0; for(scanf("%d", &tc); st++ < tc;){
        int N, L; scanf("%d %d", &N, &L);

        int n[1500];
        for(int i = 0; i < N; i++)
            scanf("%d", &n[i]);

        sort(n, n + N);

        int cnt = 0, lt = 0, t = 0, sumt = 0;
        for(int i = 0; i < N; i++){
            if(L < t + n[i]) break;
            cnt++; lt = t + n[i]; sumt += (t += n[i]);
        }

        printf("Case %d: %d %d %d\n", st, cnt, lt, sumt);
    }
    return 0;
}
