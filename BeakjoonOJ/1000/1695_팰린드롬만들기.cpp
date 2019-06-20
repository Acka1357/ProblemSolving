//
// Created by Acka on 2017. 8. 10..
//

#include <stdio.h>
#include <memory.h>
#include <algorithm>
using namespace std;

int a[5000], d[5000][5000];

int main()
{
    memset(d, 0x3f, sizeof(d));

    int N; scanf("%d %d", &N, &a[0]);
    d[0][0] = 0;
    for(int i = 1; i < N; i++){
        scanf("%d", &a[i]);
        d[i][i] = 0;
        d[i - 1][i] = (a[i - 1] == a[i] ? 0 : 1);
    }

    for(int len = 3; len <= N; len++)
        for(int l = 0, r = len - 1; r < N; l++, r++){
            if(a[l] == a[r]) d[l][r] = d[l + 1][r - 1];
            else d[l][r] = min(d[l + 1][r], d[l][r - 1]) + 1;
        }

    printf("%d\n", d[0][N - 1]);
    return 0;
}
