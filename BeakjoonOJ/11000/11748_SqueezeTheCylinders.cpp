//
// Created by Acka on 2017. 11. 17..
//

#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

int r[500];
double cent[500];

int main()
{
    int N; scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", &r[i]);

    for(int i = 0; i < N; i++){
        cent[i] = r[i];
        for(int j = 0; j < i; j++)
            cent[i] = max(cent[i], cent[j] + sqrt((r[i] + r[j]) * (r[i] + r[j]) - (r[i] - r[j]) * (r[i] - r[j])));
    }

    double ans = 0;
    for(int i = 0; i < N; i++)
        ans = max(ans, cent[i] + r[i]);
    printf("%.9lf\n", ans);
    return 0;
}
