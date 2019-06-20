//
// Created by Acka on 7/5/16.
//

#include <stdio.h>
#include <string.h>

int main()
{
    char s[51], t[51];
    scanf("%s %s", s, t);

    char a[2501] = {0,}, b[2501] = {0,};

    int ls = strlen(s), lt = strlen(t);
    for(int i = 0; i < lt; i++)
        strcat(a, s);
    for(int i = 0; i < ls; i++)
        strcat(b, t);

    printf("%d\n", strcmp(a, b) ? 0 : 1);
    return 0;
}
