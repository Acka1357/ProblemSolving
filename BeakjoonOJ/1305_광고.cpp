//
// Created by Acka on 9/17/16.
//

#include <stdio.h>

int pi[1000000];
char s[1000001];

int main()
{
    int N; scanf("%d %s", &N, s);

    for(int i = 1, j = 0; s[i]; i++){
        while(j && (s[i] != s[j]))
            j = pi[j - 1];
        if(s[i] == s[j]) pi[i] = ++j;
    }

    printf("%d\n", N - pi[N - 1]);
    return 0;
}

