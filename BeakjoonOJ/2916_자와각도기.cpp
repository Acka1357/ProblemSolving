//
// Created by Acka on 4/17/16.
//

#include <stdio.h>

int main()
{
    int N, K; scanf("%d %d", &N, &K);

    int n[10];
    for(int i = 0; i < N; i++)
        scanf("%d", &n[i]);

    bool psb[360] = {false,};
    psb[0] = true;
    for(int i = 0; i < N; i++)
        for(int k = 0; k < 360; k++)
            for(int j = 0; j < 360; j++)
                if(psb[j])
                   psb[(j - n[i] + 360) % 360] = psb[(j + n[i] + 360) % 360] = true;

    int x;
    while(K--){
        scanf("%d", &x);
        printf("%s\n", psb[x] ? "YES" : "NO");
    }

    return 0;
}
