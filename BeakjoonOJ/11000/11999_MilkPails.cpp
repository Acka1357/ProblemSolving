//
// Created by Acka on 2017. 1. 5..
//

#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
    int X, Y, M; scanf("%d %d %d", &X, &Y, &M);

    int ans = 0;
    for(int i = M / X; 0 <= i; i--)
        ans = max(ans, i * X + ((M - i * X) / Y) * Y);

    printf("%d\n", ans);
    return 0;
}
