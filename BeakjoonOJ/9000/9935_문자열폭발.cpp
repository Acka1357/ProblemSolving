//
// Created by Acka on 4/18/16.
//

#include <stdio.h>

int next[1000000];
char s[1000001], pt[37];

int remove(int ss, int ps){
    for(int i = 0; s[i]; i++)
        printf("%d ", next[i]);
    printf("\n");
    if(!pt[ps])return ss;
    if(!s[ss]) return -1;

    int ret;
    if(s[ss] == pt[ps]){
        ret = remove(next[ss], ps + 1);
        if(0 < ret){
            next[ss] = -1;
            return ret;
        }
        else if(ret) return ret;
    }

    if(ps && s[ss] == pt[0]){
        ret = remove(next[ss], ps + 1);
        if(0 < ret){
            next[ss] = -1;
            return ret;
        }
        else if(ret) return ret;
    }

    ret = remove(next[ss], 0);
    while(0 < ret){
        next[ss] = ret;
        ret = remove(next[ss], 0);
    }
    return ret;
}

int main()
{
    scanf("%s %s", s, pt);
    for(int i = 0; s[i]; i++)
        next[i] = i + 1;

    int st = remove(0, 0);
    while(0 < st) st = remove(st, 0);

    for(int i = 0; s[i]; i++)
        printf("%d ", next[i]);
    printf("\n");
    for(int i = 0; s[i]; i++)
        if(0 < next[i]) printf("%c", s[i]);
    printf("\n");

    return 0;
}
