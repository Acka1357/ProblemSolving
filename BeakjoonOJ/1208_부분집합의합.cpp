#include <stdio.h>

#define BASE    100000

int a[40], cnt[2][50 * BASE + 1], N;

void set_count(int idx, int setn, int last, int sum){
    if(idx == last){
        cnt[setn][sum]++;
        return ;
    }
    set_count(idx + 1, setn, last, sum + BASE + a[idx]);
    set_count(idx + 1, setn, last, sum + BASE);
}

int main()
{
    int N, S; scanf("%d %d", &N, &S);
    for(int i = 0; i < N; i++)
        scanf("%d", &a[i]);

    int hcnt = N / 2, tcnt = N - hcnt;
    set_count(0, 0, hcnt, 0);
    set_count(hcnt, 1, N, 0);

    long long ans = 0;
    int hbase = hcnt * BASE, tbase = tcnt * BASE, hlimit = hbase << 1;
    for(int i = 0; i <= hlimit; i++)
        if(cnt[0][i])
            ans += (long long)cnt[0][i] * cnt[1][S - i + hbase + tbase];

    printf("%lld\n", S ? ans : ans - 1);
    return 0;
}
