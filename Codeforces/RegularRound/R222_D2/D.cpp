#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;

#define INF     1000000001

struct Bug{
    int idx, lv;
    bool operator <(const Bug &A)const{
        return lv > A.lv;
    }
};

struct Stu{
    int idx, lv, cost;
    bool operator <(const Stu &A)const{
        return lv > A.lv;
    }
};

struct Info{
    int idx, lv, cost;
    Info(int i, int l, int c):idx(i), lv(l), cost(c){}
    bool operator <(const Info &A)const{
        return cost > A.cost;
    }
};

Stu stu[100001];
Bug bug[100001];

int N, M, S, ans[100001];

bool is_possible(int day){
    priority_queue<Info> q;
    int sum = 0;
    for(int si = 0, bi = 0; bi < M;) {
        while(si < N && stu[si].lv >= bug[bi].lv){
            q.push(Info(stu[si].idx, stu[si].lv, stu[si].cost));
            si++;
        }
        if(q.empty()) return false;
        sum += q.top().cost; q.pop();
        if(sum > S) return false;
        bi += day;
    }
    return true;
}


int main(){
    scanf("%d %d %d", &N, &M, &S);
    for(int i = 0; i < M; i++){
        scanf("%d", &bug[i].lv);
        bug[i].idx = i;
    }
    for(int i = 0; i < N; i++){
        scanf("%d", &stu[i].lv);
        stu[i].idx = i;
    }
    for(int i = 0; i < N; i++)
        scanf("%d", &stu[i].cost);

    sort(bug, bug + M);
    sort(stu, stu + N);

    int l = 0, r = 1000000000, m, early = -1;
    while(l <= r){
        m = (l + r) / 2;
        if(is_possible(m)){
            early = m;
            r = m - 1;
        }
        else l = m + 1;
    }

    if(early < 0) return 0 & printf("NO\n");
    else printf("YES\n");

    priority_queue<Info> q;
    for(int si = 0, bi = 0; bi < M;) {
        while(si < N && stu[si].lv >= bug[bi].lv){
            q.push(Info(stu[si].idx, stu[si].lv, stu[si].cost));
            si++;
        }
        int idx = q.top().idx; q.pop();
        for(int i = 0; i < early; i++)
            if(bi + i < M) ans[bug[bi + i].idx] = idx + 1;
        bi += early;
    }

    for(int i = 0; i < M; i++)
        printf("%d ", ans[i]);
    printf("\n");

    return 0;
}




