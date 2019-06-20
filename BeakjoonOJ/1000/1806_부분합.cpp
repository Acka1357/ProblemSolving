//
// Created by Acka on 7/5/16.
//

#include <stdio.h>

int n[100000];

int main()
{
    int N, S; scanf("%d %d", &N, &S);
    for(int i = 0; i < N; i++)
        scanf("%d", &n[i]);

    int sum = 0, l = 0, ans = 0;
    for(int i = 0; i < N; i++){
        sum += n[i];
        if(S <= sum){
            while(S <= sum) sum -= n[l++];
            if(ans) ans = (ans < (i - l + 2) ? ans : (i - l + 2));
            else ans = i - l + 2;
        }
    }

    printf("%d\n", ans);
    return 0;
}
