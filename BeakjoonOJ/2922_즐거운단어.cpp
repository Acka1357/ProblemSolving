//
// Created by Acka on 2017. 9. 6..
//

#include <stdio.h>

char s[101];
long long d[101][2][4];

int main()
{
    scanf("%s", s);

    if(s[0] == '_') d[0][0][0] = 5, d[0][0][2] = 20, d[0][1][2] = 1;
    else if(s[0] == 'L') d[0][1][2] = 1;
    else if(s[0] == 'A' || s[0] == 'E' || s[0] == 'I' || s[0] == 'O' || s[0] == 'U')
        d[0][0][0] = 1;
    else d[0][0][2] = 1;

    int len;
    for(len = 1; s[len]; len++){
        if(s[len] == '_'){
            d[len][0][0] = (d[len - 1][0][2] + d[len - 1][0][3]) * 5;
            d[len][0][1] = (d[len - 1][0][0]) * 5;
            d[len][0][2] = (d[len - 1][0][0] + d[len - 1][0][1]) * 20;
            d[len][0][3] = (d[len - 1][0][2]) * 20;
            d[len][1][0] = (d[len - 1][1][2] + d[len - 1][1][3]) * 5;
            d[len][1][1] = (d[len - 1][1][0]) * 5;
            d[len][1][2] = (d[len - 1][1][0] + d[len - 1][1][1]) * 21 + d[len - 1][0][0] + d[len - 1][0][1];
            d[len][1][3] = (d[len - 1][1][2]) * 21 + d[len - 1][0][2];
        }
        else if(s[len] == 'L'){
            d[len][1][2] = d[len - 1][1][0] + d[len - 1][1][1] + d[len - 1][0][0] + d[len - 1][0][1];
            d[len][1][3] = d[len - 1][1][2] + d[len - 1][0][2];
        }
        else if(s[len] == 'A' || s[len] == 'E' || s[len] == 'I' || s[len] == 'O' || s[len] == 'U'){
            d[len][0][0] = d[len - 1][0][2] + d[len - 1][0][3];
            d[len][0][1] = d[len - 1][0][0];
            d[len][1][0] = d[len - 1][1][2] + d[len - 1][1][3];
            d[len][1][1] = d[len - 1][1][0];
        }
        else{
            d[len][0][2] = d[len - 1][0][0] + d[len - 1][0][1];
            d[len][0][3] = d[len - 1][0][2];
            d[len][1][2] = d[len - 1][1][0] + d[len - 1][1][1];
            d[len][1][3] = d[len - 1][1][2];
        }
    }

    long long ans = 0;
    for(int i = 0; i < 4; i++)
        ans += d[len - 1][1][i];

    printf("%lld\n", ans);
    return 0;
}
