//
// Created by Acka on 2017. 7. 10..
//

#include <stdio.h>
#include <stack>
using namespace std;

stack<int> st[7];

int main()
{
    int N; scanf("%d %*d", &N);

    int cnt = 0;
    while(N--){
        int l, p; scanf("%d %d", &l, &p);
        while(!st[l].empty()){
            if(p < st[l].top()){
                st[l].pop();
                cnt++;
            }
            else break;
        }

        bool need = st[l].empty();
        if(!st[l].empty()){
            if(st[l].top() < p) need = true;
        }
        if(need){
            st[l].push(p);
            cnt++;
        }
    }

    printf("%d\n", cnt);
    return 0;
}
