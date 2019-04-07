//
// Created by Acka on 2017. 4. 14..
//

#include <stdio.h>
#include <algorithm>
using namespace std;

int a[1000000], gcd1[1000000], gcd2[1000000];

int get_gcd(int a, int b){
    int c = b;
    while(b){
        c = a;
        a = b;
        b = c % b;
    }
    return a;
}

int main()
{
    int N; scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", &a[i]);

    gcd1[0] = a[0];
    gcd2[N - 1] = a[N - 1];

    for(int i = 1; i < N; i++)
        gcd1[i] = get_gcd(gcd1[i - 1], a[i]);

    for(int i = N - 2; 0 <= i; i--)
        gcd2[i] = get_gcd(gcd2[i + 1], a[i]);

    int ans, k;
    if(gcd1[N - 2] < gcd2[1]){
        ans = gcd2[1];
        k = a[0];
    }
    else{
        ans = gcd1[N - 2];
        k = a[N - 1];
    }

    for(int i = 1; i < N - 1; i++){
        int gcd = get_gcd(gcd1[i - 1], gcd2[i + 1]);
        if(ans < gcd){
            ans = gcd;
            k = a[i];
        }
    }

    if(k % ans == 0) printf("-1\n");
    else printf("%d %d\n", ans, k);

    return 0;
}
