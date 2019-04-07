//
// Created by Acka on 2017. 8. 11..
//

#include <stdio.h>

int absx(int x){
    return x < 0 ? -x : x;
}

int main()
{
    int A, B; scanf("%d %d", &A, &B);

    int win = 0, draw = 0, lose = 0;
    for(int i = 1; i <= 6; i++){
        if(absx(A - i) == absx(B - i)) draw++;
        else if(absx(A - i) < absx(B - i)) win++;
        else lose++;
    }

    printf("%d %d %d\n", win, draw, lose);
    return 0;
}
