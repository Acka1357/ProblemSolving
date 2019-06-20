//
// Created by Acka on 7/13/16.
//

#include <stdio.h>

int absx(int a){
    return a < 0 ? -a : a;
}

int main()
{
    int X, Y; scanf("%d %d", &X, &Y);
    X = absx(X); Y = absx(Y);

    int pow3 = 1, x, y, sum3 = 1;
    while(pow3 < Y || pow3 < X) {
        pow3 *= 3; sum3 += pow3;
    }

    x = absx(absx(X) - pow3);
    y = absx(absx(Y) - pow3);
    if(sum3 - pow3 < x && sum3 - pow3 < y){
        sum3 -= pow3; pow3 /= 3;
    }

    bool psb = true;
    while(0 < pow3 && psb){
        sum3 -= pow3;
        x = absx(absx(X) - pow3); y = absx(absx(Y) - pow3);
        if(x <= sum3 && sum3 < y) X = absx(X) - pow3;
        else if(y <= sum3 && sum3 < x) Y = absx(Y) - pow3;
        else psb = false;
        pow3 /= 3;
    }

    printf("%d\n", psb && !X && !Y);
    return 0;
}
