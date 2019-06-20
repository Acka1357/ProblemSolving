//
// Created by Acka on 11/5/16.
//

#include <stdio.h>
#include <algorithm>
using namespace std;

int target[10000], cur[10000];

int main()
{
    int N, sum = 0; scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &target[i]);
        sum += target[i];
        cur[i] = i;
    }

    if(sum != (N * (N - 1)) / 2) return 0 & printf("-1\n");

    sort(target, target + N);

    for(int i = 0; i < N; i++) {
        if(target[i] < cur[i]) return 0 & printf("-1\n");
        for (int j = i + 1; j < N && cur[i] < target[i]; j++)
            if (cur[j]) {
                cur[i]++;
                cur[j]--;
            }
        printf("[%2d] ", i);
        for(int j = 0; j < N; j++){
            printf("%d:%d:%d ", j,cur[j], target[j]);
        }
        printf("\n");
        if(cur[i] != target[i]) return 0 & printf("-1\n");
    }

    printf("1\n");
    return 0;
}
