//
// Created by Acka on 5/6/16.
//

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <memory.h>
using namespace std;

int main()
{
    int N, K; scanf("%d %d", &N, &K);

    int id[100000];
    for(int i = 0; i < N; i++)
        scanf("%d", &id[i]);

    long long int x = 1;
    while((x * (x + 1)) / 2 < K) x++;

    printf("%d\n", id[K - ((x * (x - 1)) / 2) - 1]);
    return 0;
}
