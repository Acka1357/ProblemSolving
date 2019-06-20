//
// Created by Acka on 6/9/16.
//

#include <stdio.h>

int main()
{
    int tc; for(scanf("%d", &tc); tc--;){
        int B; scanf("%d ", &B);

        char c; int sum = 0;
        while(c = getchar()){
            if(c < '0' || '9' < c) break;
            sum += c - '0';
        }

        printf("%d\n", sum % (B - 1));
    }
    return 0;
}
