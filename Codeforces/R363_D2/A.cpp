//
// Created by Acka on 7/19/16.
//

#include <stdio.h>

char s[200001];
int x[200000];

int main()
{
    int N; scanf("%d %s", &N, s);

    int ans = -1;
    for(int i = 0; i < N; i++)
        scanf("%d", &x[i]);

    for(int i = 1; i < N; i++)
        if(s[i - 1] == 'R' && s[i] == 'L'){
            int t = (x[i] - x[i - 1]) / 2;
            if(ans < 0) ans = t;
            else ans = (t < ans) ? t : ans;
        }

    printf("%d\n", ans);
    return 0;
}
