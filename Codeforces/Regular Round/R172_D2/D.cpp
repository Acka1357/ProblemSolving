//
// Created by Acka on 8/9/16.
//

#include <stdio.h>
#include <stack>
#include <algorithm>
using namespace std;

int n[100000];

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &n[i]);

    stack<int> s;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        printf("%d\n", i);
        while (!s.empty()) {
            if(n[i] <= s.top()) break;
            ans = max(ans, n[i]^s.top());
        }
        if(!s.empty()) ans = max(ans, s.top()^n[i]);
        s.push(n[i]);
    }

    printf("%d\n", ans);
    return 0;
}
