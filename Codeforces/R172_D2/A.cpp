//
// Created by Acka on 8/9/16.
//

#include <stdio.h>

int main()
{
    char s[1001]; scanf("%s", s);
    printf("%c%s\n", 'a' <= s[0] && s[0] <= 'z' ? s[0] + 'A' - 'a' : s[0], s + 1);

    return 0;
}
