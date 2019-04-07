//
// Created by Acka on 2017. 4. 6..
//

#include <stdio.h>

int s[10000];

int main()
{
    int N; scanf("%d", &N);

    char cmd[6];
    int top = 0, x;
    while(N--){
        scanf("%s", cmd);
        if(cmd[0] == 's') printf("%d\n", top);
        else if(cmd[0] == 'e') printf("%d\n", top ? 0 : 1);
        else if(cmd[0] == 't') printf("%d\n", top ? s[top - 1] : -1);
        else if(cmd[1] == 'o') printf("%d\n", top ? s[--top] : -1);
        else{
            scanf("%d", &x);
            s[top++] = x;
        }
    }

    return 0;
}
