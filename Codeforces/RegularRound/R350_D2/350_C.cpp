//
// Created by Acka on 5/6/16.
//

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <memory.h>
using namespace std;

int size;

bool myfunction(int i, int j){
    return i == j;
}

int get_idx(vector<int> &v, int x){
    int l = 0, r = size - 1, m;
    while(l <= r){
        m = (l + r) / 2;
        if(v[m] == x) return m;
        else if(v[m] < x) l = m + 1;
        else r = m - 1;
    }
    return -1;
}

int main()
{
    int N; scanf("%d", &N);
    int a[200000];
    vector<int> v(N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &v[i]);
        a[i] = v[i];
    }
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());

    size = v.size();

    vector<int> cnt(size, 0);
    for(int i = 0; i < N; i++) {
        cnt[get_idx(v, a[i])]++;
    }

    int M; scanf("%d", &M);
    int b[200000];
    for(int i = 0; i < M; i++)
        scanf("%d", &b[i]);
    int c[200000];
    for(int i = 0; i < M; i++)
        scanf("%d", &c[i]);

    int max1 = -1, max2 = -1, ans = 0;
    for(int i = 0; i < M; i++){
        int idx1 = get_idx(v, b[i]), idx2 = get_idx(v, c[i]);
        int m1 = (0 <= idx1 ? cnt[idx1] : -1), m2 = (0 <= idx2 ? cnt[idx2] : - 1);
        if((max1 == m1 && max2 <= m2) || max1 < m1){
           max1 = m1; max2 = m2; ans = i + 1;
        }
    }

    printf("%d\n", ans);
    return 0;
}

