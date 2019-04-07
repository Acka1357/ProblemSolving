//
// Created by Acka on 2017. 10. 10..
//

#include <stdio.h>

int main()
{
    int R, B; scanf("%d %d", &R, &B);

    for(int w = R / 2 - 1, h; w >= 1; w--){
        h = R / 2 - w + 2;
        if(w * h == R + B){
            printf("%d %d\n", w, h);
            break;
        }
    }
    return 0;
}
