//
// Created by Acka on 2017. 8. 7..
//

#include <stdio.h>

char s[201];

int main()
{
    int N; scanf("%d %s", &N, s);

    int up = 0, down = 0;
    for(int i = 0; s[i]; i++){
        if(s[i] == 'X') up++;
        else down++;
    }

    if(up > down){
        printf("%d\n", up - N / 2);
        for(int i = 0; s[i]; i++){
            if(s[i] == 'X' && up > N / 2){
                printf("x"); up--;
            }
            else printf("%c", s[i]);
        }
    }
    else {
        printf("%d\n", down - N / 2);
        for(int i = 0; s[i]; i++){
            if(s[i] == 'x' && down > N / 2){
                printf("X"); down--;
            }
            else printf("%c", s[i]);
        }
    }
    return 0;
}

