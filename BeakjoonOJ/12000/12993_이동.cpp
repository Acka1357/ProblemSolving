//
// Created by Acka on 7/13/16.
//

#include <stdio.h>

int main()
{
    int X, Y; scanf("%d %d", &X, &Y);
    int pow3 = 1;
    while(pow3 <= Y) pow3 *= 3;
    while(pow3 <= X) pow3 *= 3;
    pow3 /= 3;

    bool psb = true;
    while(0 < pow3 && psb){
        if(pow3 <= Y && X < pow3) Y -= pow3;
        else if(pow3 <= X && Y < pow3) X -= pow3;
        else psb = false;
        pow3 /= 3;
    }

    printf("%d\n", psb && !X && !Y);
    return 0;
}
