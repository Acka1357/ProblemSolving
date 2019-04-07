//
// Created by Acka on 2017. 10. 19..
//

#include <stdio.h>
#include <string.h>
#include <memory.h>

char s[52], w[50][51];
int acc[52][26], alp_sum[50][26], len[50], d[51];

int main()
{
    int N; scanf("%s %d", s + 1, &N);
    for(int i = 0; i < N; i++){
        scanf("%s", w[i]);
        len[i] = strlen(w[i]);
        for(int j = 0; j < len[i]; j++)
            alp_sum[i][w[i][j] - 'a']++;
    }

    int slen = strlen(s + 1);
    for(int i = 1; i <= slen; i++){
        for(int j = 0; j < 26; j++)
            acc[i][j] = acc[i - 1][j];
        acc[i][s[i] - 'a']++;
    }

    memset(d, 0xff, sizeof(d));
    d[0] = 0;
    for(int li = 1; li <= slen; li++){
        if(d[li - 1] < 0) continue;
        for(int i = 0; i < N; i++){
            int ri = li + len[i] - 1;
            if(ri > slen) continue;

            bool psb = true;
            for(int j = 0; j < 26; j++)
                if(acc[ri][j] - acc[li - 1][j] != alp_sum[i][j]){
                    psb = false;
                    break;
                }
            if(!psb) continue;

            int cost = 0;
            for(int j = 0; j < len[i]; j++)
                if(s[li + j] != w[i][j]) cost++;
            if(d[ri] < 0) d[ri] = d[li - 1] + cost;
            else if(d[ri] > d[li - 1] + cost) d[ri] = d[li - 1] + cost;
        }
    }

    printf("%d\n", d[slen]);
    return 0;
}
