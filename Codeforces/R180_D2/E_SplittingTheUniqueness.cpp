//
// Created by Acka on 2017. 1. 12..
//

#include <stdio.h>
#include <algorithm>
using namespace std;

struct Num{
    int i, x;
    bool operator <(const Num &A)const{
        return x < A.x;
    }
};

Num s[100000];
int N, a[100000], b[100000];

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &s[i].x);
        s[i].i = i;
    }

    if(N == 1) return 0 & printf("YES\n0\n%d\n", s[0].x);

    sort(s, s + N);

    int T = (N - 1) / 3 + 1;
    for(int i = 0; i < T; i++){
        int& idx = s[i].i;
        a[idx] = 0;
        b[idx] = s[i].x;
    }
    for(int i = T; i < 2 * T; i++){
        int& idx = s[i].i;
        a[idx] = s[i].x;
        b[idx] = 0;
    }
    for(int i = 2 * T; i < N; i++){
        int& idx = s[i].i;
        a[idx] = N - i - 1;
        b[idx] = s[i].x - a[idx];
    }

    printf("YES\n");
    for(int i = 0; i < N; i++)
        printf("%d ", a[i]);
    printf("\n");
    for(int i = 0; i < N; i++)
        printf("%d ", b[i]);
    printf("\n");

    return 0;
}

