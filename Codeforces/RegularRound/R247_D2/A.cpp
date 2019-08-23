//
// Created by Acka on 2017. 8. 12..
//

#include <stdio.h>

int scr[4];
char s[100001];

int main()
{
    for(int i= 0; i < 4; i++)
        scanf("%d", &scr[i]);
    scanf("%s", s);

    long long ans = 0;
    for(int i = 0; s[i]; i++)
        ans += scr[s[i] - '1'];

    printf("%lld\n", ans);
    return 0;
}
