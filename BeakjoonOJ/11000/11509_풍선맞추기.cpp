//
// Created by Acka on 4/20/16.
//

#include <stdio.h>

int main()
{
    int N; scanf("%d", &N);

    int h[1000000];
    for(int i = 0; i < N; i++)
        scanf("%d", &h[i]);

    int ans = 0, cnt[1000001] = {0,};
    for(int i = 0; i < N; i++){
        if(cnt[h[i]]) cnt[h[i]]--;
        else ans++;
        cnt[h[i] - 1]++;
    }

    printf("%d\n", ans);
    return 0;
}
