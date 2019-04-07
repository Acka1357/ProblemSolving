//
// Created by Acka on 2017. 9. 6..
//

#include <stdio.h>
#include <queue>
using namespace std;

struct Fence{
    int h, idx;
    Fence(){}
    Fence(int h, int i):h(h), idx(i){}
    bool operator <(const Fence &A)const{
        return h == A.h ? idx > A.idx : h > A.h;
    }
};

int h[1000000], ch[1000000];

int main()
{
    int N, W; scanf("%d %d", &N, &W);
    for(int i = 0; i < N; i++)
        scanf("%d", &h[i]);

    priority_queue<Fence> q;
    for(int i = 0; i < W; i++)
        q.push(Fence(h[i], i));

    int l = 0, next = W;
    long long cnt = h[0] - (ch[0] = q.top().h);
    for(int i = 1; i < N; i++){
        while(l <= i && next <= N){
            if(q.top().idx < l) q.pop();
            else if((l < i && next < N && q.top().h < h[next]) || next == i){
                l++;
                q.push(Fence(h[next], next));
                next++;
            }
            else break;
        }
        cnt += h[i] - (ch[i] = q.top().h);
    }

    int roll = 1, past = 0;
    for(int i = 1; i < N; i++)
        if(i - past >= W || ch[i] != ch[past]){
            roll++;
            past = i;
        }

    printf("%lld\n%d\n", cnt, roll);
    return 0;
}

