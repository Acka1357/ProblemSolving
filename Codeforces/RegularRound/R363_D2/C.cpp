//
// Created by Acka on 7/19/16.
//

#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
    int N; scanf("%d", &N);

    int a[101], d[101][3] = {0,};
    for(int i = 1; i <= N; i++)
        scanf("%d", &a[i]);

    for(int i = 1; i <= N; i++){
        d[i][0] = max(d[i - 1][0], max(d[i - 1][1], d[i - 1][2]));
        d[i][1] = max(d[i - 1][0], d[i - 1][2]) + (a[i] == 1 || a[i] == 3);
        d[i][2] = max(d[i - 1][0], d[i - 1][1]) + (a[i] == 2 || a[i] == 3);
    }

    printf("%d\n", N - max(d[N][0], max(d[N][1], d[N][2])));
    return 0;
}

