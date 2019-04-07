//
// Created by Acka on 2017. 8. 22..
//

#include <stdio.h>

int cnt[26];

int main()
{
    int Q; scanf("%d", &Q);

    char cmd[10], x;
    int n, cur = -1, d = 1, cyc, sum = 0, rem;
    while(Q--){
        scanf("%s %d", cmd, &n);
        rem = n - sum; sum = n;

        cyc = rem / 26; rem %= 26;
        for(int i = 0; i < 26; i++)
            cnt[i] += cyc;
        while(rem--){
            cur = (cur + d + 26) % 26;
            cnt[cur]++;
        }

        if(cmd[0] == 'U'){
            scanf(" %c", &x);
            printf("%lld\n", cnt[x - 'a']);
        }
        else d *= -1;
    }
    return 0;
}
