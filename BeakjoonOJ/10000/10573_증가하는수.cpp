#include <stdio.h>

unsigned long long d[81][10][10];
char s[81];

int main()
{
    for(int i = 1; i <= 9; i++) d[1][i][i] = 1;
    for(int i = 2; i <= 80; i++)
        for(int j = 1; j <= 9; j++)
            for(int k = j; k <= 9; k++)
                for(int w = j; w <= k; w++)
                    d[i][j][k] += d[i - 1][j][w];

    int tc; for(scanf("%d", &tc); tc--;){
        scanf("%s", s);

        int len = 1, flag = 1;
        for(; s[len] && flag; len++)
            if(s[len] < s[len - 1]) flag = false;
        if(!flag){
            printf("-1\n");
            continue;
        }

        unsigned long long ans = 0;
        for(int i = 1; i < len; i++)
            for(int j = 1; j <= 9; j++)
                for(int k = j; k <= 9; k++)
                    ans += d[i][j][k];

        for(int i = 0; i < len; i++){
            for(int j = (i ? s[i - 1] - '0' : 1); j < s[i] - '0'; j++)
                for(int k = j; k <= 9; k++)
                    ans += d[len - i][j][k];
        }

        printf("%llu\n", ans + 1);
    }
    return 0;
}
