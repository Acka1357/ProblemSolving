//
// Created by Acka on 2017. 4. 14..
//

#include <stdio.h>
#include <algorithm>
using namespace std;

int a[1000001], d[1000001][2], odd[1000001], even[1000001];

int main()
{
    int N, K; scanf("%d %d", &N, &K);
    for(int i = 1; i <= N; i++){
        scanf("%d", &a[i]);
        if(a[i] & 1) odd[((i - 1) % K) + 1]++;
        else even[((i - 1) % K) + 1]++;
    }

    d[0][1] = N;
    for(int i = 1; i <= K; i++){
        d[i][0] = min(d[i - 1][0] + odd[i], d[i - 1][1] + even[i]);
        d[i][1] = min(d[i - 1][0] + even[i], d[i - 1][1] + odd[i]);
    }

    printf("%d\n", d[K][0]);
    return 0;
}
