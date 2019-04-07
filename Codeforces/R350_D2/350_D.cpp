//
// Created by Acka on 5/6/16.
//

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <memory.h>
using namespace std;

int main()
{
    int N, K; scanf("%d %d", &N, &K);

    long long int a[100000], have[100000];
    for(int i = 0; i < N; i++)
        scanf("%lld", &a[i]);
    for(int i = 0; i < N; i++)
        scanf("%lld", &have[i]);

    long long int l = 0, r = 2000000001, m, ans = 0, rem, need;
    while(l <= r){
        m = (l + r) / 2;
        rem = K;

        bool psb = true;
        for(int i = 0; i < N; i++){
            need = m * a[i];
            if(have[i] < need) {
                if(have[i] + rem < need){
                    psb = false; break;
                }
                rem -= need - have[i];
            }
        }

        if(psb){
            if(ans < m) ans = m;
            l = m + 1;
        }
        else r = m - 1;
    }

    printf("%lld\n", ans);
    return 0;
}
