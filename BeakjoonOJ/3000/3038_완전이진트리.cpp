//
// Created by Acka on 2017. 8. 4..
//

#include <stdio.h>

int tree[16][1 << 16], N;

void copy_left(int n, int cur, int pi){
    if(tree[n - 1][pi * 2]){
        tree[n][cur] = tree[n - 1][pi] * 2 + 1;
        copy_left(n, cur * 2, pi * 2);
        copy_left(n, cur * 2 + 1, pi * 2 + 1);
    }
    else tree[n][cur] = tree[n - 1][pi] * 2;
}

void copy_right(int n, int cur, int pi){
    if(tree[n - 1][pi * 2]){
        tree[n][cur] = tree[n - 1][pi] * 2;
        copy_right(n, cur * 2, pi * 2);
        copy_right(n, cur * 2 + 1, pi * 2 + 1);
    }
    else tree[n][cur] = tree[n - 1][pi] * 2 + 1;
}

void print_order(int cur){
    printf("%d ", tree[N][cur]);
    if(tree[N][cur * 2]){
        print_order(cur * 2);
        print_order(cur * 2 + 1);
    }
}

int main()
{
    tree[1][1] = tree[2][1] = 1;

    scanf("%d", &N);
    for(int i = 2; i <= N; i++){
        tree[i][1] = 1;
        copy_left(i, 2, 1);
        copy_right(i, 3, 1);
   }

    print_order(1);
    printf("\n");

    return 0;
}

