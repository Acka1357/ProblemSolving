//
// Created by Acka on 2017. 4. 8..
//

#include <stdio.h>
#include <string.h>

char s[1001];

int main()
{
    freopen("/Users/Acka/ClionProjects/ProblemSolving/Codejam/17_Qualification/A-large.in", "r", stdin);
    freopen("/Users/Acka/ClionProjects/ProblemSolving/Codejam/17_Qualification/A_large.out", "w", stdout);

    int T, tc = 0; for(scanf("%d", &T); tc++ < T;){
        int K; scanf("%s %d", s, &K);

        int ans = 0, len = strlen(s);
        for(int i = 0; i <= len - K; i++)
            if(s[i] == '-'){
                for(int j = 0; j < K; j++){
                    if(s[i + j] == '-') s[i + j] = '+';
                    else s[i + j] = '-';
                }
                ans++;
            }

        for(int i = 0; i < K; i++)
            if(s[len - i - 1] == '-') ans = -1;

        printf("Case #%d: ", tc);
        if(ans < 0) printf("IMPOSSIBLE\n");
        else printf("%d\n", ans);
    }
    return 0;
}
