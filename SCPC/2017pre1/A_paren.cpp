//
// Created by Acka on 2017. 6. 30..
//

#include <stdio.h>
#include <string.h>
#include <queue>
#include <memory.h>
#include <algorithm>
using namespace std;

int maxl[1000001];
char s[1000002];
char match[256];

int main()
{
    match['('] = ')';
    match['{'] = '}';
    match['['] = ']';

    int T, tc = 0; for(scanf("%d ", &T); tc++ < T;){
        fgets(s, 1000002, stdin);
        int sl = strlen(s);

        memset(maxl, 0, (sl + 1) * sizeof(maxl[0]));
        for(int i = sl - 1; i >= 0; i--){
            maxl[i] = maxl[i] + maxl[i + maxl[i]];
            if(i){
                if(match[s[i - 1]] == s[i + maxl[i]]){
                    maxl[i - 1] = maxl[i] + 2;
                }
            }
        }

        int ans = -1;
        for(int i = 0; i < sl; i++)
            ans = max(ans, maxl[i]);

        printf("Case #%d\n%d\n", tc, ans);
    }
    return 0;
}

