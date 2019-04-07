//
// Created by Acka on 2016. 11. 27..
//

#include <stdio.h>
#include <memory.h>
#include <algorithm>
using namespace std;

#define MOD 1000000007

long long int d[2][5000];
int h[10000], maxh[10000], minh[10000];

int main()
{
    int N; scanf("%d", &N);
    for(int i = 0, half = N / 2; i < N; i++) {
        scanf("%d", &h[i]);
        maxh[i] = (i < half ? i : N - i - 1);
    }

    for(int i = 0; i < N; i++)
        if(h[i] != -1){
            minh[i] = h[i];
            maxh[i] = min(maxh[i], h[i]);
            for(int j = i - 1, h1 = h[i] - 1, h2 = h[i] + 1; 0 <= j; j--, h1--, h2++) {
                minh[j] = max(minh[j], h1);
                maxh[j] = min(maxh[j], h2);
            }
            for(int j = i + 1, h1 = h[i] - 1, h2 = h[i] + 1; j < N; j++, h1--, h2++) {
                minh[j] = max(minh[j], h1);
                maxh[j] = min(maxh[j], h2);
            }
        }

    for(int i = 0; i < N; i++)
        if (maxh[i] < minh[i]) return 0 & printf("0\n");

    int t = 0, half = (N + 1) / 2; d[t][0] = 1;
    for(int i = 1; i < N; i++, t = !t) {
        for (int j = minh[i]; j <= maxh[i]; j++) {
            if (j) d[!t][j] += d[t][j - 1];
            if (j < half - 1) d[!t][j] += d[t][j + 1];
            d[!t][j] = (d[!t][j] + d[t][j]) % MOD;
        }
        memset(d[t], 0, half * sizeof(d[t][0]));
    }

    printf("%lld\n", d[t][0]);
    return 0;
}

