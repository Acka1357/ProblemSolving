//
// Created by Acka on 2017. 8. 22..
//

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

struct Stud{
    int a, idx;
    Stud(int a, int i):a(a), idx(i){}
    bool operator <(const Stud &A)const{
        return a < A.a;
    }
};

int tree[1 << 19], NN;

int range_max(int ql, int qr, int idx = 1, int l = 0, int r = NN - 1){
    if(r < ql || qr < l) return -1;
    if(ql <= l && r <= qr) return tree[idx];
    return max(range_max(ql, qr, idx * 2, l, (l +r )/ 2),
               range_max(ql, qr, idx * 2 + 1, (l + r) / 2 + 1, r));
}

void update_max(int idx, int val){
    if(tree[NN + idx] >= val) return ;
    tree[NN + idx] = val;
    for(idx = (NN + idx) / 2; idx > 0; idx >>= 1)
        tree[idx] = max(tree[idx * 2], tree[idx * 2 + 1]);
}

char cmd[200000];
int N, q[200000], bs[200000], a[200000], b[200000];
int bcnt;
vector<Stud> s[200000];
map<int, int> conv;
set<Stud> line[200000];

void find_q(int qa, int qb){
    if(tree[NN + qb] > qa){
        printf("%d\n", line[qb].upper_bound(Stud(qa, - 1))->idx + 1);
        return ;
    }

    int l = qb + 1, r = bcnt - 1, m, ans = -1;
    while(l <= r){
        m = (l + r) / 2;
        if(range_max(qb + 1, m) >= qa){
            ans = m;
            r = m - 1;
        }
        else l = m + 1;
    }
    if(ans < 0) printf("NE\n");
    else printf("%d\n", line[ans].upper_bound(Stud(qa - 1, -1))->idx + 1);
}

int main()
{
    scanf("%d", &N);

    int dcnt = 0, qcnt = 0;
    for(int i = 0; i < N; i++){
        scanf(" %c", &cmd[i]);
        if(cmd[i] == 'D'){
            scanf("%d %d", &a[dcnt], &b[dcnt]);
            bs[dcnt] = b[dcnt]; dcnt++;
        }
        else scanf("%d", &q[qcnt++]);
    }

    sort(bs, bs + dcnt);

    conv[bs[0]] = bcnt++;
    for(int i = 1; i < dcnt; i++)
        if(bs[i] != bs[i - 1]){
            conv[bs[i]] = bcnt;
            bs[bcnt++] = bs[i];
        }

    for(int i = 0; i < dcnt; i++)
        b[i] = conv[b[i]];

    for(NN = 1; NN < bcnt; NN *= 2);

    int di = 0, qi = 0;
    for(int i = 0; i < N; i++){
        if(cmd[i] == 'D'){
            update_max(b[di], a[di]);
            line[b[di]].insert(Stud(a[di], di));
            di++;
        }
        else{
            find_q(a[q[qi] - 1], b[q[qi] - 1]);
            qi++;
        }
    }

    return 0;
}
