//
// Created by Acka on 2017. 9. 3..
//

#include <stdio.h>

int N, M, use[100000];

bool psb(int k){
    int cnt = 0, cur = 0;
    for(int i = 0; i < N; i++){
        if(cur < use[i]){
            if(cnt++ == M) return false;
            cur = k;
        }
        cur -= use[i];
    }
    return true;
}

int main()
{
    scanf("%d %d", &N, &M);

    int l = 0, r = 1000000000, m, ans = -1;
    for(int i = 0; i < N; i++){
        scanf("%d", &use[i]);
        if(l < use[i]) l = use[i];
    }

    while(l <= r){
        m = (l + r) / 2;
        if(psb(m)){
            ans = m;
            r = m - 1;
        }
        else l = m + 1;
    }

    printf("%d\n", ans);
    return 0;
}
