//
// Created by Acka on 2017. 10. 20..
//

#include <stdio.h>
#include <memory.h>
#include <algorithm>
using namespace std;

char s[2502];
int d[2501];

int main()
{
    scanf("%s", s + 1);

    memset(d, 0x3f, sizeof(d));
    d[0] = 0;

    int i;
    for(i = 1; s[i]; i++){
        for(int j = 0; j < i; j++){
            if(s[i - j] != s[i + j]) break;
            d[i + j] = min(d[i + j], d[i - j - 1] + 1);
        }
        for(int j = 1; j < i; j++){
            if(s[i - j] != s[i + j - 1]) break;
            d[i + j - 1] = min(d[i + j - 1], d[i - j - 1] + 1);
        }
    }

    printf("%d\n", d[i - 1]);
    return 0;
}
