//
// Created by Acka on 4/17/16.
//

#include <stdio.h>

int main()
{
    int n[26] = {3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 10, 10, 10, 10};

    char s[16]; scanf("%s", s);

    int ans = 0;
    for(int i = 0; s[i]; i++)
        ans += n[s[i] - 'A'];

    printf("%d\n", ans);
    return 0;
}
