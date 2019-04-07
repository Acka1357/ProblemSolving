//
// Created by Acka on 2017. 8. 9..
//

#include <stdio.h>
#include <string.h>

int len;
char org[51], ans[51], cur[51];

void find_lex(int idx, int l){
    if(idx == 2 && l < len){
        for(int i = l; i < len; i++)
            cur[l + len - i - 1] = org[i];
        if(strcmp(ans, cur) > 0) strcpy(ans, cur);
        return ;
    }
    for(int i = l; i < len; i++){
        for(int j = l; j <= i; j++)
            cur[l + i - j] = org[j];
        find_lex(idx + 1, i + 1);
    }
}

int main()
{
    scanf("%s", org);
    len = strlen(org);
    for(int i = 0; i < len; i++) ans[i] = 'z';
    find_lex(0, 0);
    printf("%s\n", ans);
    return 0;
}
