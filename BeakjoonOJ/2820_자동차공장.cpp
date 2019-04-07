//
// Created by Acka on 2017. 4. 13..
//

#include <stdio.h>
#include <vector>
using namespace std;

vector<int> adj[500001];
int org[500001], tree[1 << 21], in[500001], out[500001], NN, t;

void set_index(int cur){
    in[cur] = ++t;
    for(int i = 0; i < adj[cur].size(); i++)
        set_index(adj[cur][i]);
    out[cur] = t;
}

void add_value(int idx, int value){
    if(NN < idx) return ;
    int cur= NN + idx - 1;
    tree[cur] += value;
    cur /= 2;
    while(0 < cur){
        tree[cur] =tree[cur * 2] + tree[cur * 2 + 1];
        cur /= 2;
    }
}

int get_sum(int ql, int qr, int idx, int l, int r){
    if(qr < l || r < ql) return 0;	// ql qr l r, l r ql qr
    if(ql <= l && r <= qr) return tree[idx];	// ql l r qr
    return get_sum(ql, qr, idx * 2, l, (l + r) / 2)
           + get_sum(ql, qr, idx * 2 + 1, (l + r) / 2 + 1, r);
}

int main()
{
    int N, M; scanf("%d %d", &N, &M);

    NN = 1;
    while(NN < N) NN *= 2;

    scanf("%d", &org[1]);
    for(int i = 2; i <= N; i++){
        int p;
        scanf("%d %d", &org[i], &p);
        adj[p].push_back(i);
    }

    set_index(1);

    while(M--){
        char cmd; scanf(" %c", &cmd);
        if(cmd == 'p'){
            int a, x; scanf("%d %d", &a, &x);
            add_value(in[a] + 1, x);
            add_value(out[a] + 1, -x);
        }
        else{
            int a; scanf("%d", &a);
            printf("%d\n", org[a] + get_sum(1, in[a], 1, 1, NN));
        }
    }

    return 0;
}
