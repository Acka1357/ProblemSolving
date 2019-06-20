//
// Created by Acka on 7/7/16.
//

#include <stdio.h>
#include <vector>
using namespace std;

#define MOD 1000000007

long long int d[10][100001];
vector<int> dv[100001];

int main()
{
    int N, K; scanf("%d %d", &N, &K);

    d[0][0] = K;
    for(int i = 1; i <= K; i++)
        d[0][i] = 1;

    for(int i = 2; i <= K; i++) {
        dv[i].push_back(1);
        for (long long int j = 2; j * j <= i; j++)
            if (!(i % j)) {
                dv[i].push_back(j);
                if (j * j != i) dv[i].push_back(i / j);
            }
    }

    int maxc = 0;
    int L = 100000;
    long long int sum1 = 0, sum2 = 0;
    for(int i = 1; i <= L; i++){
        sum1 += L / i;
        sum2 += dv[i].size();
        if(maxc < dv[i].size()) {
            maxc = dv[i].size();
            printf("%d\n", i);
        }
    }
    printf("%d\n", maxc);


    for(int i = 1; i < N; i++)
        for(int j = 1; j <= K; j++){
            d[i][j] = d[i - 1][0];
            for(int k = j * 2; k <= K; k += j)
                d[i][j] -= d[i - 1][k];

            if(d[i][j] < 0) d[i][j] += ((-d[i][j] / MOD) + 1) * MOD;
            d[i][j] %= MOD;

            d[i][0] = (d[i][0] + d[i][j]) % MOD;
        }

    printf("%lld\n", d[N - 1][0]);
    return 0;
}
