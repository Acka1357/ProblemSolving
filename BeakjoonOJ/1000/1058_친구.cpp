//
// Created by Acka on 4/18/16.
//

#include <stdio.h>

int main()
{
    int N; scanf("%d", &N);

    bool d1[50][50], d2[50][50] = {false};
    char temp;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++){
            scanf(" %c", &temp);
            d1[i][j] = (temp == 'Y');
        }

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            if(d1[i][j])
                for (int k = 0; k < N; k++)
                    if (d1[j][k]) d2[i][k] = true;

    int ans = 0;
    for(int i = 0; i < N; i++){
        int cnt = 0;
        for(int j = 0; j < N; j++)
            if(i != j && (d1[i][j] || d2[i][j])) cnt++;
        if(ans < cnt) ans = cnt;
    }

    printf("%d\n", ans);
    return 0;
}
