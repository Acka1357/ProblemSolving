//
// Created by Acka on 2017. 1. 14..
//

#include <stdio.h>
#include <stack>
using namespace std;

int a[1000001], d[1000001] = {-1000000001}, idx[1000001], p[1000001];

int main()
{
    int N; scanf("%d", &N);

    int ans = 0, ansi = 0;
    for(int i = 1; i <= N; i++){
        scanf("%d", &a[i]);

        int l = 0, r = ans + 1, m;
        while(l < r){
            m = (l + r) / 2;
            if(d[m] < a[i]) l = m + 1;
            else r = m;
        }

        if(ans < r) ans = r, ansi = i;
        d[r] = a[i]; idx[r] = i; p[i] = idx[r - 1];
    }

    printf("%d\n", ans);

    stack<int> st;
    while(ansi) st.push(a[ansi]), ansi = p[ansi];
    while(!st.empty()) printf("%d ", st.top()), st.pop();
    printf("\n");

    return 0;
}
