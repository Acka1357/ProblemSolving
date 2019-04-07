//
// Created by Acka on 4/23/16.
//

#include <stdio.h>

int main()
{
    int tc; for(scanf("%d", &tc); tc--;){
        int N; scanf("%d", &N);

        bool chk[101] = {false,};
        for(int i = 1; i <= N; i++)
            for(int j = i; j <= N; j+= i)
                chk[j] = !chk[j];

        int cnt = 0;
        for(int i = 1; i <= N; i++)
            if(chk[i]) cnt++;

        printf("%d\n", cnt);
    }
    return 0;
}
