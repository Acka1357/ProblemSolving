//
// Created by Acka on 2017. 8. 25..
//

#include <stdio.h>

int N, a[10000], idx = 1;
int child[100001][2];

void set_tree(int cur, int minv, int maxv){
    if(idx < N && a[idx] < cur && a[idx] < maxv){
        child[cur][0] = a[idx++];
        set_tree(child[cur][0], minv, cur);
    }
    if(idx < N && a[idx] > cur && a[idx] < maxv){
        child[cur][1] = a[idx++];
        set_tree(child[cur][1], cur, maxv);
    }
}

void print_post(int cur){
    if(child[cur][0]) print_post(child[cur][0]);
    if(child[cur][1]) print_post(child[cur][1]);
    printf("%d\n", cur);
}

int main()
{
    while(scanf("%d\n", &a[N]) == 1) N++;
    set_tree(a[0], -1, 1000001);
    print_post(a[0]);
    return 0;
}
