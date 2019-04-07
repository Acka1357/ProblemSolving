//
// Created by Acka on 2017. 1. 12..
//

#include <stdio.h>
#include <stack>
using namespace std;

int a[1001], d[1001][2];

int main()
{
    int N; scanf("%d", &N);
    for(int i = 1; i <= N; i++)
        scanf("%d", &a[i]);

    int maxl, pasti, ansi = 0;
    for(int i = 1; i <= N; i++) {
        maxl = pasti = 0;
        for (int j = 1; j < i; j++)
            if(a[j] < a[i] && maxl < d[j][0]){
                maxl = d[j][0];
                pasti = j;
            }

        d[i][0] = maxl + 1;
        d[i][1] = pasti;
        if(d[ansi][0] < d[i][0]) ansi = i;
    }

    printf("%d\n", d[ansi][0]);

    stack<int> st;
    while(ansi){
        st.push(a[ansi]);
        ansi = d[ansi][1];
    }

    while(!st.empty()){
        printf("%d ", st.top());
        st.pop();
    }
    printf("\n");

    return 0;
}
