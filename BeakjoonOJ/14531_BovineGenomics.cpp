//
// Created by Acka on 2017. 8. 13..
//

#include <stdio.h>

char s[100][101], ns[100][101];

int main()
{
    int N, M; scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++)
        scanf("%s", s[i]);
    for(int i = 0; i < N; i++)
        scanf("%s", ns[i]);

    int ans = 0;
    for(int i = 0; i < M; i++){
        bool chk1[26] = {false,}, chk2[26] = {false,};
        for(int j = 0; j < N; j++){
            chk1[s[j][i] - 'A'] = true;
            chk2[ns[j][i] - 'A'] = true;
        }

        bool dif = true;
        for(int i = 0; i < 26; i++)
            if(chk1[i] && chk2[i]) dif = false;

        if(dif) ans++;
    }

    printf("%d\n", ans);
    return 0;
}
