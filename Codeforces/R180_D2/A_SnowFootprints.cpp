//
// Created by Acka on 2017. 1. 12..
//

#include <stdio.h>

char s[1002];

int main()
{
    int N; scanf("%d %s", &N, s);
    s[N] = '.'; s[++N] = '\0';

    int ans[3] = {0,}, cur = 0, dir = 1;
    while(s[cur] == '.') cur++;
    if(s[cur] == 'L'){
        while(s[cur] != '.') cur++;
        cur--; dir *= -1;
    }
    printf("%d ", cur + 1);
    while(true){
        bool chk = true;
        while(s[cur] != '.'){
            if((dir == 1 && s[cur] == 'L') ||
                    (dir == -1 && s[cur] == 'R')) {
                chk = false;
            }

            if(chk) s[cur] = '.';
            cur += dir;
        }
        dir *= -1;
        cur += dir;
        if(chk) break;
    }

    printf("%d\n", cur + 1 - dir);
    return 0;
}
