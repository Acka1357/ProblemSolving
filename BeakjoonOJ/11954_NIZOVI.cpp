//
// Created by Acka on 4/17/16.
//

#include <stdio.h>

int main()
{
    char s[1501], sp[1501] = {0,};
    scanf("%s", s);

    bool f = true;
    for(int i = 0, sx = 0; s[i]; i++){
        if(s[i] == '{'){
            printf("%s{\n", sp);
            sp[sx++] = ' '; sp[sx++] = ' ';
        }
        else if(s[i] == '}'){
            sp[--sx] = 0; sp[--sx] = 0;
            printf("%s%s}", (s[i - 1] == '{' || s[i - 1] == ',' ? "" : "\n"), sp);
        }
        else if(s[i] == ','){
            printf(",\n");
            f = true;
        }
        else if(f){
            printf("%s%c", sp, s[i]);
            f = false;
        }
        else printf("%c", s[i]);
    }

    printf("\n");
    return 0;
}

