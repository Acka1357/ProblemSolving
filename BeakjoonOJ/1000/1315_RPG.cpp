//
// Created by Acka on 7/24/16.
//

#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;

struct Quest{
    int st, it, p;
    Quest(){} Quest(int s, int i):st(s), it(i){}
};

bool chk[1001][1001];
int d[1001][1001][2];
Quest qst[101];

int main()
{
    int N; scanf("%d", &N);

    qst[0].st = qst[0].it = 1;
    for(int i = 1; i <= N; i++)
        scanf("%d %d %d", &qst[i].st, &qst[i].it, &qst[i].p);

    int st, it;
    for(int i = 0; i <= N; i++)
        for(int j = 0; j <= N; j++){
            st = qst[i].st; it = qst[j].it;
            if(d[st][it][0]) continue;

            for(int k = 1; k <= N; k++)
                if(qst[k].st <= st || qst[k].it <= it){
                    d[st][it][0] += qst[k].p;
                    d[st][it][1]++;
                }
        }

    chk[1][1] = true;
    queue<Quest> q; q.push(Quest(1, 1));

    int ans = 0, ad;
    while(!q.empty()){
        st = q.front().st;
        it = q.front().it;
        q.pop();

        ans = max(ans, d[st][it][1]);

        ad = d[st][it][0] - st - it + 2;
        for(int i = 1; i <= N; i++) {
            if (st <= qst[i].st && qst[i].st - st <= ad){
                if(!chk[qst[i].st][it]){
                    chk[qst[i].st][it] = true;
                    q.push(Quest(qst[i].st, it));
                }
            }
            if (it <= qst[i].it && qst[i].it - it <= ad){
                if(!chk[st][qst[i].it]){
                    chk[st][qst[i].it] = true;
                    q.push(Quest(st, qst[i].it));
                }
            }

        }
    }

    printf("%d\n", ans);
    return 0;
}

