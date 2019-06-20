//
// Created by Acka on 10/18/16.
//

#include <stdio.h>
#include <string.h>

char s[10];

int calc_dist(int l, int half, int chk){
    int front = 0, rear = 0;
    for(int i = 0; i < half; i++){
        front *= 10;
        front += s[half - i - 1] - '0';
        rear *= 10;
        rear += s[half + i - chk] - '0';
    }
    return front - rear;
}

int main()
{
    while(scanf("%s", s) == 1){
        if(!s[1] && s[0] == '0') break;

        int l = strlen(s), half = (l + 1) / 2, chk = l & 1, base = 0;
        if(calc_dist(l, half, chk) < 0){
            int x = 0, d = 1;
            for(int i = 0; i < half - chk; i++){
                x *= 10;
                x += s[half + i] - '0';
                s[half + i] = '0';
                d *= 10;
            }

            base = d - x;
            s[half - 1]++;

            for(int i = l - 1; 0 <= i; i--)
                if('9' < s[i]){
                    s[i] = '0';
                    s[i - 1]++;
                }
        }

        printf("%d\n", base + calc_dist(l, half, chk));
    }
    return 0;
}
