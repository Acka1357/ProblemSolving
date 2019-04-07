//
// Created by Acka on 2017. 11. 7..
//

#include <stdio.h>
#include <queue>
#include <list>
using namespace std;

struct Lake{
    int idx, next;
    Lake(int i, int n):idx(i), next(n){}
    bool operator <(const Lake &o)const{
        return next > o.next;
    }
};

queue<int, list<int>> f[1000001];
int rain[1000001], ans[1000001], add[1000001];

int main()
{
    int tc; for(scanf("%d", &tc); tc--;){
        int N, M; scanf("%d %d", &N, &M);
        for(int i = 1; i <= N; i++)
            while(!f[i].empty()) f[i].pop();

        for(int i = 1; i <= M; i++){
            scanf("%d", &rain[i]);
            if(rain[i]) f[rain[i]].push(i);
        }

        priority_queue<Lake> q;
        for(int i = 1; i <= N; i++)
            if(!f[i].empty()){
                q.push(Lake(i, f[i].front()));
                f[i].pop();
            }

        bool psb = true;
        int ansi = 0;
        for(int i = 1; i <= M; i++){
            if(rain[i]){
                if(!f[add[i]].empty()){
                    q.push(Lake(add[i], f[add[i]].front()));
                    f[add[i]].pop();
                }
                if(!q.empty() && q.top().next <= i){
                    psb = false; break;
                }
            }
            else if(!q.empty()){
                int cur = q.top().idx, day = q.top().next; q.pop();
                ans[ansi++] = cur;
                add[day] = cur;
            }
            else ans[ansi++] = 0;
        }

        if(psb){
            printf("YES\n");
            for(int i = 0; i < ansi; i++)
                printf("%d ", ans[i]);
            printf("\n");
        }
        else printf("NO\n");
    }
    return 0;
}
