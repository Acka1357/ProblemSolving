//
// Created by Acka on 2017. 6. 8..
//

#include <stdio.h>

int K, n[13], ans[6];

void print_ans(int nth, int idx){
    if(nth >= 6){
        for(int i = 0; i < 6; i++)
            printf("%d ", ans[i]);
        printf("\n");
        return ;
    }

    for(int i = idx; i < K; i++){
        ans[nth] = n[i];
        print_ans(nth + 1, i + 1);
    }
}

int main()
{
    for(int tc = 0; ; tc++){
        scanf("%d", &K);
        if(!K) break;

        for(int i = 0; i < K; i++)
            scanf("%d", &n[i]);

        if(tc) printf("\n");
        print_ans(0, 0);
    }
    return 0;
}
