//
// Created by Acka on 7/19/16.
//

#include <stdio.h>
#include <string.h>

int main()
{
    char s[251];
    while(scanf("%s", s) == 1){
        for(int i = 0, x, l = strlen(s); i < l; i += 2){
            if('0' <= s[i] && s[i] <= '9') x = s[i] - '0';
            else x = s[i] - 'A' + 10;
            if('0' <= s[i + 1] && s[i + 1] <= '9') x = x * 16 + s[i + 1] - '0';
            else x = x * 16 + s[i + 1] - 'A' + 10;
            printf("%c", x);
        }
        printf("\n");
    }
    return 0;
}
