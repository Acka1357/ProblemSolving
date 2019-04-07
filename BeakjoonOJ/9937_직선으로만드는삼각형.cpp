//
// Created by Acka on 2017. 8. 12..
//

#include <stdio.h>
#include <algorithm>
using namespace std;

#define MOD     1000000007

struct Line{
    int x, y;
    double d;
    bool operator <(const Line &A)const{
        return d < A.d;
    }
};

long long mult(long long mul3, long long a, long long b){
    if(mul3 % 2 == 0) return ((mul3 / 6) * (((a * b)) % MOD)) % MOD;
    return ((mul3 / 3) * (((a * b) / 2) % MOD)) % MOD;
}

Line line[300000];
long long dcnt[300000], didx;

int main()
{
    int N; scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d %d %*d", &line[i].x, &line[i].y);
        if(line[i].y == 0) line[i].d = 1000000001;
        line[i].d = (double)line[i].x / line[i].y;
     }
    if(N <= 2) return 0 & printf("0\n");

    sort(line, line + N);

    dcnt[didx] = 1;
    for(int i = 1 ; i < N; i++){
        if(line[i].d == line[i - 1].d) dcnt[didx]++;
        else dcnt[++didx] = 1;
    }


    long long ans;
    if(N % 3 == 0) ans = mult(N, N - 1, N - 2);
    else if(N % 3 == 1) ans = mult(N - 1, N, N - 2);
    else ans = mult(N - 2, N, N - 1);

    long long ex = 0;
    for(int i = 0; i <= didx; i++)
        if(dcnt[i] > 1){
            if(dcnt[i] >= 3){
                if(dcnt[i] % 3 == 0) ex += mult(dcnt[i], dcnt[i] - 1, dcnt[i] - 2);
                else if(dcnt[i] % 3 == 1) ex += mult(dcnt[i] - 1, dcnt[i], dcnt[i] - 2);
                else ex += mult(dcnt[i] - 2, dcnt[i], dcnt[i] - 1);
            }
            ex += (((((dcnt[i] * (dcnt[i] - 1) / 2) % MOD)) * (N - dcnt[i]))) % MOD;
            ex %= MOD;
        }

    printf("%lld\n", (ans - ex + MOD) % MOD);
    return 0;
}
