//
// Created by Acka on 4/18/16.
//

#include <stdio.h>

int main()
{
    int a, b, n; scanf("%d %d %d", &a, &b, &n);
    while(n--){
        a = a % b;
        a *= 10;
    }
    printf("%d\n", a / b);
    return 0;
}
