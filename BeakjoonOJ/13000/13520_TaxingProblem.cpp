//
// Created by Acka on 11/12/16.
//

#include <stdio.h>
#include <algorithm>
using namespace std;

int B;
double tax[21][2];

double calc_after(double am){
    double sum = 0;
    for(int i = 0; i < B; i++){
        sum += min(am, tax[i][0]) * tax[i][1];
        am -= tax[i][0];
        if(am <= 0) break;
    }
    return sum;
}

int main()
{
    scanf("%d", &B);

    for(int i = 0; i < B; i++)
        scanf("%lf %lf", &tax[i][0], &tax[i][1]);
    scanf("%lf", &tax[B][1]);
    tax[B++][0] = 200000000001LL;

    for(int i = 0; i < B; i++)
        tax[i][1] = (100 - tax[i][1]) / 100;

    int F; for(scanf("%d", &F); F--;){
        double E, M; scanf("%lf %lf", &E, &M);

        int it = 100;
        double org = calc_after(E), sum = org + M, l = sum, r = 200000000000LL, m, af;
        while(it--){
            m = (l + r) / 2;
            af = calc_after(m);
            if(af < sum) l = m;
            else r = m;
        }
        printf("%.10lf\n", r - E);
    }

    return 0;
}
