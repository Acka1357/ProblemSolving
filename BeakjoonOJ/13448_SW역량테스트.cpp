//
// Created by Acka on 10/26/16.
//

#include <stdio.h>
#include <algorithm>
using namespace std;

struct Munje{
    int org, dec, t;
    double order;
    bool operator <(const Munje &A)const{
        return order < A.order;
    }
};

int d[100001];
Munje list[50];

int main()
{
    int N, T; scanf("%d %d", &N, &T);
    for(int i = 0; i < N; i++)
        scanf("%d", &list[i].org);
    for(int i = 0; i < N; i++)
        scanf("%d", &list[i].dec);
    for(int i = 0; i < N; i++) {
        scanf("%d", &list[i].t);
        list[i].order = list[i].t / (double)list[i].dec;
    }

    sort(list, list + N);

    for(int i = 0; i < N; i++) {
        for (int t = T; list[i].t <= t; t--) {
            if ((long long) list[i].dec * t < list[i].org)
                d[t] = max(d[t], d[t - list[i].t] + list[i].org - list[i].dec * t);
        }
        for(int t = 1; t <= T; t++)
            if(d[t] < d[t - 1]) d[t] = d[t - 1];
    }

    printf("%d\n", d[T]);
    return 0;
}

