//
// Created by Acka on 2017. 2. 17..
//

#include <stdio.h>

#define MOD     1000000

long long mat[65][2][2], temp[2][2];

void mat_mult(long long a[][2], long long b[][2], long long c[][2]){
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++) {
            temp[i][j] = 0;
            for (int k = 0; k < 2; k++)
                temp[i][j] += a[i][k] * b[k][j];
        }

    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            c[i][j] = temp[i][j] %= MOD;
}

int main()
{
    mat[0][0][0] = mat[0][1][1] =
    mat[1][0][1] = mat[1][1][0] = mat[1][1][1] = 1;

    long long int N; scanf("%lld", &N);

    long long int n = 1, ex = 1;
    while(n < N){
        mat_mult(mat[ex], mat[ex], mat[ex + 1]);
        n <<= 1; ex++;
    }

    while(0 < N){
        if(n <= N){
            mat_mult(mat[0], mat[ex], mat[0]);
            N -= n;
        }
        n >>= 1; ex--;
    }

    printf("%d\n", mat[0][0][1]);
    return 0;
}

