//
// Created by Acka on 2017. 6. 8..
//

#include <stdio.h>

int N, R, C, step;

int calc_ans(int t, int l, int q){
    if(!q) return step;
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++){
            int nt = t + q * i, nl = l + q * j;
            if(nt <= R && R < nt + q && nl <= C && C < nl + q)
                return calc_ans(nt, nl, q / 2);
            else step += q * q;
        }
}

int main()
{
    scanf("%d %d %d", &N, &R, &C);
    printf("%d\n", calc_ans(0, 0, 1 << (N - 1)));
    return 0;
}
