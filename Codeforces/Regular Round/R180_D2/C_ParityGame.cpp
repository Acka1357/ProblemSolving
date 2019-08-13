//
// Created by Acka on 2017. 1. 12..
//

#include <stdio.h>

char a[1001], b[1001];

int main()
{
    scanf("%s %s", a, b);

    int cnt1 = 0, cnt2 = 0;
    for(int i = 0; a[i]; i++)
        cnt1 += a[i] == '1';
    for(int i = 0; b[i]; i++)
        cnt2 += b[i] == '1';

    if(cnt1 & 1) cnt1++;
    printf("%s\n", cnt1 < cnt2 ? "NO" : "YES");
    return 0;
}
