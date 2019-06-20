//
// Created by Acka on 2017. 1. 5..
//

#include <stdio.h>
#include <algorithm>
using namespace std;

int r[1000];

int main()
{
    int N; scanf("%d", &N);

    for(int i = 0; i < N; i++)
        scanf("%d", &r[i]);

    int ans = 1000000000;
    for(int i = 0; i < N; i++){
        int sum = 0;
        for(int j = 0; j < N; j++)
            sum += j * r[(i + j) % N];
        ans = min(ans, sum);
    }

    printf("%d\n", ans);
    return 0;
}
