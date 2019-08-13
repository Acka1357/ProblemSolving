//
// Created by Acka on 8/8/16.
//

#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
    int N; scanf("%d", &N);

    int a[100];
    for(int i = 0; i < N; i++)
        scanf("%d", &a[i]);

    sort(a, a + N);

    int l = 1, r = N, m, ans = N;
    while(l <= r){
        m = (l + r) / 2;

        bool psb = true;
        int cnt[100] = {0,}, k = 0;
        for(int j = 0; j < N; j++){
            if(a[j] < cnt[k]){
                psb = false; break;
            }
            cnt[k++]++;
            if(m <= k) k = 0;
        }

        if(psb){
            ans = m; r = m - 1;
        }
        else l = m + 1;
    }

    printf("%d\n", ans);
    return 0;
}
