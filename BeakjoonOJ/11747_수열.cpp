//
// Created by Acka on 2017. 11. 17..
//

#include <stdio.h>

bool chk[100000];
int d[1000];

int main()
{
    int N; scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", &d[i]);

    for(int i = 0, cur; i < N; i++)
        for(int l = cur = 0; l < 5; l++){
            if(i + l == N) break;
            cur = cur * 10 + d[i + l];
            chk[cur] = true;
        }

    for(int i = 0; i < 100000; i++)
        if(!chk[i]){
            printf("%d\n", i);
            break;
        }

    return 0;
}
