//
// Created by Acka on 8/9/16.
//

#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

double absx(double x){
    return x < 0 ? -x : x;
}
const double PI = acos(-1.0);

int main()
{
    long long int W, H, A; scanf("%lld %lld %lld", &W, &H, &A);
    if(A == 90) return printf("%.10lf\n", (double)min(W, H) * min(W, H));

    if(A > 90) A = 180 - A;
    double x = cos((A * PI) / 180), y = sin((A * PI) / 180);

    double a = ((x + 1) * W - y * H) / ((x + 1) * (x + 1) - y * y);
    double b = (y * W - (x + 1) * H) / (y * y - (x + 1) * (x + 1));
    printf("%.10lf %.10lf %.10lf %.10lf\n", x, y, a, b);
    printf("%lld - %.10lf\n", W * H, a * a * x * y + b * b * x * y);
    printf("%.10lf\n", W * H - (a * a * x * y + b * b * x * y));

    return 0;
}
