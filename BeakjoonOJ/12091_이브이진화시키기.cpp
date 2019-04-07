//
// Created by Acka on 2017. 8. 2..
//

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main()
{
    int i;
    srand((uintptr_t)&i);
    int r = rand() % 3;
    if (r == 0) printf("Vaporeon\n");
    else if(r == 1) printf("Jolteon\n");
    else printf("Flareon\n");
    return 0;
}
