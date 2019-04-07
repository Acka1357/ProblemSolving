//
// Created by Acka on 2017. 1. 10..
//

#include <stdio.h>
#include <algorithm>
using namespace std;

int N, Q, cur[100001];
long long tree[100001];

long long get_acc(int idx){
    long long sum = 0;
    while(0 < idx){
        sum += tree[idx];
        idx -= idx & -idx;
    }
    return sum;
}

void add_val(int idx, long long int v){
    while(idx <= N){
        tree[idx] += v;
        idx += idx & -idx;
    }
}


int main()
{
    scanf("%d %d", &N, &Q);
    for(int i = 1; i <= N; i++){
        scanf("%d", &cur[i]);
        add_val(i, cur[i]);
    }

    int x, y, a, b; while(Q--){
        scanf("%d %d %d %d", &x, &y, &a, &b);
        if(y < x) swap(x, y);
        printf("%lld\n", get_acc(y) - get_acc(x - 1));
        add_val(a, (long long)b - cur[a]);
        cur[a] = b;
    }

    return 0;
}
