//
// Created by Acka on 2017. 9. 1..
//

#include <stdio.h>
#include <memory.h>
#include <string.h>

char s[33], cur[33];

int main()
{
    int tc; for(scanf("%d", &tc); tc--;){
        scanf("%s", s);
        memset(cur, '0', sizeof(cur));

        int len = strlen(s), ans = 0, b = (1 << (len - 1));
        for(int i = 0; s[i + 1]; i++, b >>= 1)
            if(cur[i] != s[i]){
                ans += b;
                cur[i + 1] = '1';
            }
        printf("%d\n", ans + (cur[len - 1] == s[len - 1] ? 0 : 1));
    }
    return 0;
}
