//
// Created by Acka on 2017. 10. 10..
//

#include <stdio.h>

int main()
{
    double a[4]; scanf("%lf %lf %lf %lf", &a[0], &a[1], &a[3], &a[2]);

    int ans = -1;
    double maxv = -1, v;
    for(int i = 1; i <= 4; i++){
        v = a[i % 4] / a[(3 + i) % 4] + a[(1 + i) % 4] / a[(2 + i) % 4];
        if(maxv < v){
            maxv = v;
            ans = i;
        }
    }

    printf("%d\n", 4 - ans);
    return 0;
}
