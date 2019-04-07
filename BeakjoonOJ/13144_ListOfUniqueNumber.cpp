//
// Created by Acka on 8/30/16.
//

#include <stdio.h>
#include <queue>
using namespace std;

bool chk[100001];

int main()
{
    int N; scanf("%d", &N);

    int a[100000];
    for(int i = 0; i < N; i++)
        scanf("%d", &a[i]);

    queue<int> q;
    long long int ans = 0;
    for(int i = 0; i < N; i++){
        if(!chk[a[i]]){
            q.push(a[i]);
            chk[a[i]] = true;
            ans++;
        }
        else{
            while(q.front() != a[i]){
                chk[q.front()] = false;
                q.pop();
                ans += q.size();
            }
            q.pop();
            q.push(a[i]);
            ans += q.size();
        }
    }

    printf("%lld\n", ans + ((long long)q.size() * (q.size() - 1)) / 2);
    return 0;
}
