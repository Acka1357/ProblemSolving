//
// Created by Acka on 2017. 8. 2..
//

#include <stdio.h>

int row[11];

int main()
{
    int N; scanf("%d", &N);
    for(int i = 1, x; i <= N; i++){
        scanf("%d", &x);

        int cnt = 0;
        for(int j = 1; j <= N; j++)
            if(!row[j]){
                if(cnt++ == x){
                    row[j] = i;
                    break;
                }
            }
    }

    for(int i = 1; i <= N; i++)
        printf("%d ", row[i]);
    printf("\n");
    return 0;
}
