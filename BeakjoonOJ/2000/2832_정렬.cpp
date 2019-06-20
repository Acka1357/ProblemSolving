//
// Created by Acka on 2017. 7. 14..
//

#include <stdio.h>
#include <algorithm>
using namespace std;

int N, a[100001], tree[100001];

int add_val(int idx, int val){
    for(int i = idx; i <= N; i += (i & -i))
        tree[i] += val;
}

int get_acc(int r){
    int sum = 0;
    for(int i = r; i > 0; i -= (i & -i))
        sum += tree[i];
    return sum;
}

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", &a[i]);

    long long ans = 0, r;
    for(int i = 0; i < N; i = r + 1){
        for(r = i; r < N - 1 && a[r] > a[r + 1]; r++);
        if(r != i){
            for(int j = r; i < j; i++, j--)
                swap(a[i], a[j]);
            ans++;
        }
    }

    for(int i = 0; i < N; i++){
        ans += i - get_acc(a[i]);
        add_val(a[i], 1);
    }

    printf("%lld\n", ans);
    return 0;
}
