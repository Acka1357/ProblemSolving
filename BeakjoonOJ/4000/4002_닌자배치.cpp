#include <stdio.h>
#include <vector>
#include <memory.h>
using namespace std;

struct Ninja{
    int c, l, ti;
    Ninja(){} Ninja(int c, int l): c(c), l(l){}
};

struct Return{
    long long int cnt, sum;
    Return(){} Return(long long int c, long long int s):cnt(c), sum(s){}
};

int N, M, tree[262144], tcnt;
Ninja ninja[100001];
vector<int> adj[100001];
long long int ans, nearn;

void set_idx(int cur){
    ninja[cur].ti = tcnt++;
    for(int i = adj[cur].size() - 1; 0 <= i; i--)
        set_idx(adj[cur][i]);
}

int get_max(int ql, int qr, int l, int r, int idx){
    if((ql <= l && r <= qr) || tree[idx] < 0) return tree[idx];

    int half = (l + r) / 2, maxn1 = -1, maxn2 = -1;
    if(ql <= half) maxn1 = get_max(ql, qr, l, half, idx * 2);
    if(half < qr) maxn2 = get_max(ql, qr, half + 1, r, idx * 2 + 1);

    if(maxn1 < 0) return maxn2;
    else if(maxn2 < 0) return maxn1;
    return ninja[maxn1].c < ninja[maxn2].c ? maxn2 : maxn1;
}

void update(int n, int v){
    tree[nearn + ninja[n].ti] = v;
    for(int i = (nearn + ninja[n].ti) >> 1; 0 < i; i >>= 1){
        if(tree[i * 2] < 0) tree[i] = tree[i * 2 + 1];
        else if(tree[i * 2 + 1] < 0) tree[i] = tree[i * 2];
        else tree[i] = (ninja[tree[i * 2]].c < ninja[tree[i * 2 + 1]].c ? tree[i * 2 + 1] : tree[i * 2]);
    }
}

void remove(int n){
    tree[nearn + ninja[n].ti] = -1;
    for(int i = (nearn + ninja[n].ti) >> 1; 0 < i; i >>= 1){
        if(tree[i * 2] < 0) tree[i] = tree[i * 2 + 1];
        else if(tree[i * 2 + 1] < 0) tree[i] = tree[i * 2];
        else tree[i] = (ninja[tree[i * 2]].c < ninja[tree[i * 2 + 1]].c ? tree[i * 2 + 1] : tree[i * 2]);
    }
}

Return get_sub(int cur){
    Return ret;
    long long int sum = 0, cnt = 0;
    for(int i = adj[cur].size() - 1; 0 <= i; i--) {
        ret = get_sub(adj[cur][i]);
        sum += ret.sum; cnt += ret.cnt;
    }

    update(cur, cur);
    sum += ninja[cur].c; cnt++;

    int bign = -1;
    while(M < sum){
        bign = get_max(ninja[cur].ti, nearn - 1, 0, nearn - 1, 1);
        remove(bign);
        sum -= ninja[bign].c; cnt--;
    }

    ans = max(ans, ninja[cur].l * cnt);
    return Return(cnt, sum);
}

int main()
{
    memset(tree, 0xff, sizeof(tree));

    scanf("%d %d", &N, &M);

    for(int i = 1, b; i <= N; i++){
        scanf("%d %d %d", &b, &ninja[i].c, &ninja[i].l);
        adj[b].push_back(i);
    }

    set_idx(adj[0][0]);

    for(nearn = 1; nearn < N; nearn <<= 1);

    get_sub(adj[0][0]);

    printf("%lld\n", ans);
    return 0;
}
