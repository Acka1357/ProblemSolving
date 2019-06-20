//
// Created by Acka on 10/24/16.
//

#include <stdio.h>

char s[10001];
short d[10000][10000], cnt[10000];

int main()
{
    int N, K, L; scanf("%d %d %d %s", &N, &K, &L, s);
    for(int l = 1; l < N; l++)
        for(int i = 0; i < N - l; i++)
            d[i][i + l] = (s[i] == s[i + l] ? d[i + 1][i + l - 1] + 1 : 0);

    L <<= 1;
    for(int i = 0; i < N; i++){
        cnt[i] = ((i + 1) * K <= L * d[0][i]);
        for(int j = 1; j <= i; j++)
            if(cnt[j - 1] && (i - j + 1) * K <= L * d[j][i]){
                if(!cnt[i]) cnt[i] = cnt[j - 1] + 1;
                else if(cnt[j - 1] + 1 < cnt[i]) cnt[i] = cnt[j - 1] + 1;
            }
    }

    printf("%d\n", cnt[N - 1]);
    return 0;
}
