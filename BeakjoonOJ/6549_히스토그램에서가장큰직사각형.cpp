//
// Created by Acka on 11/9/16.
//

#include <stdio.h>
#include <stack>
#include <algorithm>
using namespace std;

struct Info{
    int h, left;
    Info(){} Info(int l, int h):left(l),h(h){}
};

int h[100002], N;

int main()
{
    while(scanf("%d", &N) == 1){
        if(!N) break;

        for(int i = 1; i <= N; i++)
            scanf("%d", &h[i]);

        h[++N] = 0;

        stack<Info> s; s.push(Info(0, 0));
        long long int ans = 0;
        for(int i = 1; i <= N; i++){
            int left = i;
            while(h[i] < s.top().h){
                ans = max(ans, (long long)s.top().h * (i - s.top().left));
                left = s.top().left; s.pop();
            }
            s.push(Info(left, h[i]));
        }

        printf("%lld\n", ans);
    }
    return 0;
}
