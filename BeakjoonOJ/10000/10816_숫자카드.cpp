//
// Created by Acka on 2017. 11. 8..
//

#include <stdio.h>
#include <algorithm>
using namespace std;

int N, a[500000];

int lower_idx(int x){
    int l = 0, r = N - 1, m, ret = -1;
    while(l <= r){
        m = (l + r) / 2;
        if(a[m] < x) l = m + 1, ret = m;
        else r = m - 1;
    }
    return ret;
}

int upper_idx(int x){
    int l = 0, r = N - 1, m, ret = -1;
    while(l <= r){
        m = (l + r) / 2;
        if(a[m] <= x) l = m + 1, ret = m;
        else r = m - 1;
    }
    return ret;
}

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", &a[i]);

    sort(a, a + N);

    int Q; scanf("%d", &Q);
    for(int i = 0, x; i < Q; i++){
        scanf("%d", &x);
        printf("%d ", upper_idx(x) - lower_idx(x));
    }
    printf("\n");

    return 0;
}
