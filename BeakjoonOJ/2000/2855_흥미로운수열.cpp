//
// Created by Acka on 2017. 11. 6..
//

#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int a[100001], cum[100001], d[100001];

int main()
{
    int N, S; scanf("%d %d", &N, &S);
    for(int i = 1; i <= N; i++)
        scanf("%d", &a[i]);
    for(int i = 1; i <= N; i++)
        cum[i] = cum[i - 1] + a[i];

    for(int i = 1; i < N; i++){
        int l = 1, r = i, m, lm = i + 1, rm = i - 1;
        while(l <= r){
            m = (l + r) / 2;
            if(cum[i] - cum[m - 1] <= S) lm = m, r = m - 1;
            else l = m + 1;
        }
        l = i + 1, r = N;
        while(l <= r){
            m = (l + r) / 2;
            if(cum[m] - cum[i] <= S) rm = m, l = m + 1;
            else r = m - 1;
        }
        if(lm <= i && i < rm){
            int len = min(i - lm + 1, rm - i);
            d[i - len + 1] = max(d[i - len + 1], len);
        }
    }

    int pmax = 0;
    for(int i = 1; i <= N; i++){
        printf("%d\n", max(2 * (pmax - 1), 2 * d[i]));
        pmax = max(pmax - 1, d[i]);
    }
    return 0;
}
