//
// Created by Acka on 7/19/16.
//

#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
    int D; scanf("%d", &D);
    int A = 0, B = 0, C = 0;
    while(D--){
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        A += a; B += b; C += c;
        int x = min(A, min(B, C));
        if(x < 30) printf("NO\n");
        else{
            printf("%d\n", x);
            A -= x; B -= x; C -= x;
        }
    }

    return 0;
}

