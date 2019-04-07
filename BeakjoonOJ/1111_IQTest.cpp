#include <stdio.h>

int n[50];

int main()
{
    int N; scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", &n[i]);

    if(N <= 2){
        if(N == 2 && n[0] == n[1]) printf("%d\n", n[0]);
        else printf("A\n");
        return 0;
    }

    int cnt = 0, ans;
    for(int a = -200; a <= 200; a++){
        int b = n[1] - n[0] * a;
        bool psb = true;
        for(int i = 2; i < N; i++)
            if(n[i - 1] * a + b != n[i]){
                psb = false;
                break;
            }
        if(psb){
            if(cnt && n[N - 1] * a + b != ans) return 0 & printf("A\n");
            else cnt++, ans = n[N - 1] * a + b;
        }
    }

    if(!cnt) printf("B\n");
    else printf("%d\n", ans);
    return 0;
}
