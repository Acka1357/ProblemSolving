//
// Created by Acka on 2017. 8. 1..
//

#include <stdio.h>

int main()
{
    int N; scanf("%d", &N);

    int wait[1000], wcnt = 0, safe = 0;
    for(int i = 0, x; i < N; i++){
        scanf("%d", &wait[wcnt++]);
        while(0 < wcnt && wait[wcnt - 1] == safe + 1){
            safe++; wcnt--;
        }
    }

    printf("%s\n", wcnt ? "Sad" : "Nice");
    return 0;
}
