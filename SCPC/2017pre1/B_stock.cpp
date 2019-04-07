//
// Created by Acka on 2017. 6. 30..
//

#include <stdio.h>

int d[200000];

int main()
{
    d[0] = 1000000001;
    int T, tc = 0; for(scanf("%d ", &T); tc++ < T;){
        int N; scanf("%d", &N);

        int ans = 0;
        for(int i = 0, p; i < N; i++){
            scanf("%d", &p);
            if(ans & 1){
                if(p > d[ans]) d[++ans] = p;
                else d[ans] = p;
            }
            else{
                if(p < d[ans]) d[++ans] = p;
                else d[ans] = p;
            }
        }

        printf("Case #%d\n%d\n", tc, ans - (ans & 1));
    }
    return 0;
}

