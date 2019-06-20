//
// Created by Acka on 2017. 5. 22..
//

#include <stdio.h>
#include <algorithm>
using namespace std;

int cut[10002];

int main()
{
    int L, K, C; scanf("%d %d %d", &L, &K, &C);
    for(int i = 1; i <= K; i++)
        scanf("%d", &cut[i]);

    cut[0] = 0; cut[K + 1] = L;
    sort(cut + 1, cut + K + 1);
    K += 2;

    int ans = L, l = 0, r = L, m;
    for(int i = 1; i < K; i++)
        if(cut[i] - cut[i - 1] > l){
            l = cut[i] - cut[i - 1];
        }

    while(l <= r){
        m = (l + r) / 2;

        int cut_cnt = 0, last = 0;
        for(int i = 1; i < K; i++)
            if(cut[i] - last > m){
                cut_cnt++;
                last = cut[i - 1];
            }

        if(cut_cnt <= C){
            ans = m;
            r = m - 1;
        }
        else l = m + 1;
    }

    int last = L, cut_cnt = 0;
    for(int i = K - 2; i >= 0; i--)
        if(last - cut[i] > ans) {
            cut_cnt++;
            last = cut[i + 1];
        }

    if(cut_cnt < C) last = cut[1];
    printf("%d %d\n", ans, last);
    return 0;
}
