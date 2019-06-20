//
// Created by Acka on 4/18/16.
//

#include <stdio.h>
#include <math.h>

int main()
{
    double PI = acos(-1);

    long long int r; scanf("%lld", &r);
    printf("%.6lf\n%.6lf\n", r * r * PI, r * r * 2.0);

    return 0;
}
