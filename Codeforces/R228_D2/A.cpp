//
// Created by Acka on 8/8/16.
//

#include <stdio.h>

int get_gcd(int a, int b){
    int temp = b;
    while(b){
        temp = a; a = b; b = temp % b;
    }
    return a;
}

int main()
{
    int N; scanf("%d", &N);
    int a[100];
    for(int i = 0; i < N; i++)
        scanf("%d", &a[i]);

    int ans = a[0];
    for(int i = 1; i < N; i++)
        ans = get_gcd(ans, a[i]);

    printf("%d\n", ans * N);
    return 0;
}
