//
// Created by Acka on 2017. 10. 11..
//

#include <stdio.h>
#include <algorithm>
using namespace std;

struct String{
    char s[1001];
};

int N, L, cmpl;

bool cmp(String &a, String &b){
    for(int i = cmpl; i < L; i++)
        if(a.s[i] != b.s[i]) return a.s[i] < b.s[i];
    return false;
}

String s[1000];

bool is_psb(int sl){
    cmpl = sl;
    sort(s, s + N, cmp);

    for(int i = 1; i < N; i++){
        bool same = true;
        for(int j = sl; j < L && same; j++)
            if(s[i].s[j] != s[i - 1].s[j]) same = false;
        if(same) return false;
    }
    return true;
}

int main()
{
    scanf("%d %d", &L, &N);
    for(int i = 0; i < L; i++)
        for(int j = 0; j < N; j++)
            scanf(" %c", &s[j].s[i]);

    int l = 0, r = L, m, ans = 0;
    while(l <= r){
        m = (l + r) / 2;
        if(is_psb(m)){
            ans = m;
            l = m + 1;
        }
        else r = m - 1;
    }

    printf("%d\n", ans);
    return 0;
}
