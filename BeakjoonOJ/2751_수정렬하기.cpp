//
// Created by Acka on 2017. 5. 23..
//

#include <stdio.h>

int a[1000000], ordered[1000000];

void merge_sort(int l, int r){
    if (r - l < 2){
        if (a[r] < a[l]){
            int temp = a[l];
            a[l] = a[r]; a[r] = temp;
        }
        return;
    }

    int half = (l + r) / 2;
    merge_sort(l, half); merge_sort(half + 1, r);

    int idx = l, li = l, ri = half + 1;
    while (li <= half && ri <= r){
        if (a[li] <= a[ri]) ordered[idx++] = a[li++];
        else ordered[idx++] = a[ri++];
    }

    while (li <= half) ordered[idx++] = a[li++];
    while (ri <= r) ordered[idx++] = a[ri++];

    for (int i = l; i <= r; i++)
        a[i] = ordered[i];
}

int main()
{
    int N; scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", &a[i]);

    merge_sort(0, N - 1);

    for(int i = 0; i < N; i++)
        printf("%d\n", a[i]);

    return 0;
}
