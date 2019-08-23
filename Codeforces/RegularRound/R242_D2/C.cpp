//
// Created by Acka on 2017. 8. 7..
//

#include <stdio.h>

int p[1000001], cnt[1000001];

int main()
{
    int N; scanf("%d", &N);
    for(int i = 1; i <= N; i++)
        scanf("%d", &p[i]);

    int ans = 0;
    for(int i = 1; i <= N; i++){
        ans ^= p[i];
        if((N - i) & 1) ans ^= i;
        int r = (N - i) / i + 1;
        if(r & 1){
            cnt[0]++;
            cnt[((N - i) % i) + 1]--;
        }
        else{
            cnt[((N - i) % i) + 1]++;
            cnt[i]--;
        }
    }

    int sum = 0;
    for(int i = 0; i <= N; i++){
        sum += cnt[i];
        if(sum & 1) ans ^= i;
    }

    printf("%d\n", ans);
    return 0;
}

