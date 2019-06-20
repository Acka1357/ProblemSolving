//
// Created by Acka on 2017. 11. 3..
//

#include <stdio.h>

char org[201];

bool check(char *s){
    if(!s[0]) return true;
    if(s[0] == '0'){
        if(s[1] != '1') return false;
        if(check(s + 2)) return true;
    }
    else{
        if(s[1] != '0' || s[2] != '0') return false;
        int idx = 2;
        while(s[idx] == '0') idx++;
        while(s[idx] == '1') idx++;
        if(s[idx - 1] != '1') return false;
        if(check(s + idx)) return true;
        if(s[idx - 2] == '1' && check(s + idx - 1)) return true;
    }
    return false;
}

int main()
{
    int tc; for(scanf("%d", &tc); tc--;){
        scanf("%s", org);
        printf("%s\n", check(org) ? "YES" : "NO");
    }
    return 0;
}
