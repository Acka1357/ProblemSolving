//
// Created by Acka on 4/26/16.
//

#include <stdio.h>

int main()
{
    int x, cnt = 0; scanf("%d", &x);
    while(x){
        if(x & 1) cnt++;
        x >>= 1;
    }
    printf("%d\n", cnt == 1 ? 1 : 0);
    return 0;
}
