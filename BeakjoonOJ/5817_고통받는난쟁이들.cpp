//
// Created by Acka on 2017. 8. 22..
//

#include <stdio.h>
#include <algorithm>
using namespace std;

#define MIN_DUMMY       200001
#define MAX_DUMMY       -1

struct Node{
    int mini, maxi;
    Node():mini(MIN_DUMMY), maxi(MAX_DUMMY){}
    Node(int mini, int maxi):mini(mini), maxi(maxi){}
};

Node merge_node(Node left, Node right){
    return Node(min(left.mini, right.mini), max(left.maxi, right.maxi));
}

int NN, num[200001];
Node tree[1 << 19];

Node range_ans(int ql, int qr, int idx = 1, int l = 1, int r = NN){
    if(r < ql || qr < l) return Node();
    if(ql <= l && r <= qr) return tree[idx];
    return merge_node(range_ans(ql ,qr ,idx * 2, l, (l + r) / 2),
                      range_ans(ql, qr, idx * 2 + 1, (l + r) / 2 + 1, r));
}

void change_value(int idx, int val){
    tree[NN + idx - 1] = Node(val, val);
    for(idx = (NN + idx - 1) >> 1; idx > 0; idx >>= 1)
        tree[idx] = merge_node(tree[idx * 2], tree[idx * 2 + 1]);
}

int main()
{
    int N, M; scanf("%d %d", &N, &M);
    for(NN = 1; NN < N; NN *= 2);
    for(int i = 1; i <= N; i++){
        scanf("%d", &num[i]);
        tree[NN + num[i] - 1] = Node(i, i);
    }
    for(int i = NN - 1; i > 0; i--)
        tree[i] = merge_node(tree[i * 2], tree[i * 2 + 1]);

    Node ret;
    for(int cmd, a, b, ax, bx; M--;){
        scanf("%d %d %d", &cmd, &a, &b);
        if(cmd == 1){
            ax = num[a]; bx = num[b];
            change_value(ax, b);
            change_value(bx, a);
            num[a] = bx; num[b] = ax;
        }
        else{
            ret = range_ans(a, b);
            printf("%s\n", (ret.maxi - ret.mini == b - a) ? "YES" : "NO");
        }
    }
    return 0;
}
