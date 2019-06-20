//
// Created by Acka on 11/2/16.
//

#include <stdio.h>

int N, T, h[100000], a[100000], ans[100000];

bool is_psb(int x){
    int sum = 0;
    a[0] = h[0];
    for(int i = 1; i < N; i++) {
        a[i] = h[i];
        if(a[i - 1] + x < a[i]){
            sum += a[i] - a[i - 1] - x;
            a[i] = a[i - 1] + x;
            if(T < sum) return false;
        }
    }

    for(int i = N - 2; 0 <= i; i--)
        if(a[i + 1] + x < a[i]){
            sum += a[i] - a[i + 1] - x;
            a[i] = a[i + 1] + x;
            if(T < sum) return false;
        }

    return true;
}

int main()
{
    scanf("%d %d", &N, &T);
    for(int i = 0; i < N; i++)
        scanf("%d", &h[i]);

    int l = 0, r = 1000000000, m;
    while(l <= r){
        m = (l + r) / 2;
        if(is_psb(m)){
            for(int i = 0; i < N; i++)
                ans[i] = a[i];
            r = m - 1;
        }
        else l = m + 1;
    }

    for(int i = 0; i < N; i++)
        printf("%d ", ans[i]);
    printf("\n");
    return 0;
}
