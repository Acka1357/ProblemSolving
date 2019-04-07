//
// Created by Acka on 2017. 8. 12..
//

#include <stdio.h>
#include <memory.h>

const long long MAX = 1000000000000000000ll;

long long M, K;
long long d[66][66][2], cnt[66][66], digit[66];

long long count(long long X){
    memset(d, 0, sizeof(d));
    memset(cnt, 0, sizeof(cnt));

    int len = 0;
    while(X){
        digit[len] = X & 1;
        X >>= 1;
        len++;
    }

    d[len][1][1] = 1;
    for(int i = len - 1; i > 0; i--)
        for(int j = 1; j <= len; j++){
            if(digit[i]){
                d[i][j][0] = d[i + 1][j - 1][0] + d[i + 1][j][0] + d[i + 1][j][1];
                d[i][j][1] = d[i + 1][j - 1][1];
            }
            else{
                d[i][j][0] = d[i + 1][j - 1][0] + d[i + 1][j][0];
                d[i][j][1] = d[i + 1][j][1];
            }
        }

    cnt[1][1]  = 1;
    for(int i = 2; i < len; i++)
        for(int j = 1; j <= len; j++)
            cnt[i][j] = cnt[i - 1][j] + cnt[i - 1][j - 1];

    long long sum = d[1][K][0] + d[1][K][1];
    for(int i = 2; i < len; i++)
        sum += cnt[i][K];

    return sum;
}

int main()
{
    scanf("%lld %lld", &M, &K);
    if(K == 1) return 0 & printf("1\n");

    long long l = 1, r = MAX, m, ans;
    while(l <= r){
        m = (l + r) / 2;
        printf("%lld %lld %lld\n", m, count(m * 2), count(m));
        if(count(m * 2) - count(m) >= M){
            ans = m;
            r = m - 1;
        }
        else l = m + 1;
    }

    printf("%lld\n", ans);
    return 0;
}
