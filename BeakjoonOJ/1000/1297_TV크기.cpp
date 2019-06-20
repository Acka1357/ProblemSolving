//
// Created by Acka on 4/18/16.
//

#include <stdio.h>
#include <math.h>

int main()
{
    int x, h, w; scanf("%d %d %d", &x, &h, &w);
    double a = sqrt((x * x) / (double)(h * h + w * w)) + 1e-9;
    printf("%d %d\n", (int)(a * h), (int)(a * w));
    return 0;
}
