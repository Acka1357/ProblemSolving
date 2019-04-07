//
// Created by Acka on 2017. 5. 24..
//

#include <stdio.h>

int acc[100001];

int main()
{
    int N, M; scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++)
        scanf("%d", &acc[i]);

    for(int i = 1; i <= N; i++)
        acc[i] += acc[i - 1];

    int l, r;
    while(M--){
        scanf("%d %d", &l, &r);
        printf("%d\n", acc[r] - acc[l - 1]);
    }

    return 0;
}
