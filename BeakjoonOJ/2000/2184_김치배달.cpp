//
// Created by Acka on 8/30/16.
//

#include <stdio.h>
#include <algorithm>
using namespace std;

long long int d[1000][1000][2];
int x[1000];

long long int absx(int x){
    return x < 0 ? -x : x;
}

int main()
{
    long long int N, L; scanf("%lld %lld", &N, &L);
    for(int i = 0; i < N; i++)
        scanf("%d", &x[i]);

    sort(x, x + N);

    for(int i = 0; i < N; i++)
        d[i][i][0] = d[i][i][1] = (absx(x[i] - L)) * N + 1;

    for(int len = 0; len < N; len++)
        for(int l = 0, r = len; r < N; l++, r++){
            if(d[l][r][0]){
                if(l) {
                    if (!d[l - 1][r][0]) d[l - 1][r][0] = d[l][r][0] + (x[l] - x[l - 1]) * (N - len - 1);
                    else d[l - 1][r][0] = min(d[l - 1][r][0], d[l][r][0] + (x[l] - x[l - 1]) * (N - len - 1));
                }
                if(r < N - 1){
                    if(!d[l][r + 1][1]) d[l][r + 1][1] = d[l][r][0] + (x[r + 1] - x[l]) * (N - len - 1);
                    else d[l][r + 1][1] = min(d[l][r + 1][1], d[l][r][0] + (x[r + 1] - x[l]) * (N - len - 1));
                }
            }
            if(d[l][r][1]){
                if(l) {
                    if (!d[l - 1][r][0]) d[l - 1][r][0] = d[l][r][1] + (x[r] - x[l - 1]) * (N - len - 1);
                    else d[l - 1][r][0] = min(d[l - 1][r][0], d[l][r][1] + (x[r] - x[l - 1]) * (N - len - 1));
                }
                if(r < N - 1){
                    if(!d[l][r + 1][1]) d[l][r + 1][1] = d[l][r][1] + (x[r + 1] - x[r]) * (N - len - 1);
                    else d[l][r + 1][1] = min(d[l][r + 1][1], d[l][r][1] + (x[r + 1] - x[r]) * (N - len - 1));
                }
            }
        }

    printf("%lld\n", min(d[0][N - 1][0], d[0][N - 1][1]) - 1);
    return 0;
}
