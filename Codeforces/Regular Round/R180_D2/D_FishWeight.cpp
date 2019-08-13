//
// Created by Acka on 2017. 1. 12..
//

#include <stdio.h>
#include <algorithm>
using namespace std;

int a[100001], b[100001];

int main()
{
    int N, M; scanf("%d %d %*d", &N, &M);
    for(int i = 0; i < N; i++)
        scanf("%d", &a[i]);
    for(int i = 0; i < M; i++)
        scanf("%d", &b[i]);

    sort(a, a + N);
    sort(b, b + M);

    bool ans = M < N;
    for(int ai = N - 1, bi = M - 1; 0 <= ai && !ans;)
        if(b[bi--] < a[ai--]) ans = true;

    printf("%s\n", ans ? "YES" : "NO");
    return 0;
}

