//
// Created by Acka on 2016. 12. 10..
//

#include <stdio.h>
#include <algorithm>
using namespace std;

int N, K, a[50000], d1[50000], d2[50000];

int main()
{
    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; i++)
        scanf("%d", &a[i]);

    sort(a, a + N);

    d1[0] = d1[N - 1] = 1;
    for(int i = 0, l = 0; i < N; i++){
        if(K < a[i] - a[l]) l++;
        if(i) d1[i] = max(d1[i - 1], i - l + 1);
    }

    for(int i = N - 1, r = N - 1; 0 <= i; i--){
        if(K < a[r] - a[i]) r--;
        if(i < N - 1) d2[i] = max(d2[i + 1], r - i + 1);
    }

    int ans = 2;
    for(int i = 0; i < N - 1; i++)
        ans = max(ans, d1[i] + d2[i + 1]);

    printf("%d\n", ans);
    return 0;
}
