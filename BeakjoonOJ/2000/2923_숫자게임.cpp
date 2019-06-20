//
// Created by Acka on 2017. 9. 6..
//

#include <stdio.h>

int acnt[101], bcnt[101];

int main()
{
    int N, a, b; scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d %d", &a, &b);

        acnt[a]++; bcnt[b]++;
        int ai = 1, bi = 100, arem = acnt[1], brem = bcnt[100], ans = 0;
        while(ai <= 100 && bi >= 1){
            if(arem && brem && ans < ai + bi) ans = ai + bi;
            if(arem > brem){
                arem -= brem;
                brem = bcnt[--bi];
            }
            else if(brem > arem){
                brem -= arem;
                arem = acnt[++ai];
            }
            else{
                arem = acnt[++ai];
                brem = bcnt[--bi];
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
