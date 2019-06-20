//
// Created by Acka on 2017. 5. 25..
//

#include <stdio.h>
#include <algorithm>
using namespace std;

#define IDENT_MIN    100000
#define IDENT_MAX    0

struct Node{
    int minx, maxx;
    Node(){}
    Node(int minx, int maxx):minx(minx), maxx(maxx){}
};

Node merge_info(const Node left, const Node right){
    return Node(min(left.minx, right.minx), max(left.maxx, right.maxx));
}

Node tree[4000001];
int NN;

Node range_info(int ql, int qr, int idx, int l, int r){
    if(ql <= l && r <= qr) return tree[idx];
    if(qr < l || r < ql) return Node(IDENT_MIN, IDENT_MAX);
    return merge_info(range_info(ql, qr, idx * 2, l, (l + r) / 2),
                      range_info(ql, qr, idx * 2 + 1, (l + r) / 2 + 1, r));
}

void change_value(int idx, int value){
    tree[NN + idx] = Node(value, value);
    for(int cur = (NN + idx) / 2; cur > 0; cur /= 2)
        tree[cur] = merge_info(tree[cur * 2], tree[cur * 2 + 1]);
}

int main()
{
    int tc; for(scanf("%d", &tc); tc--;){
        int N, K; scanf("%d %d", &N, &K);
        for(NN = 1; NN < N; NN <<= 1);

        for(int i = 0; i < N; i++)
            tree[NN + i] = Node(i, i);
        for(int i = N; i < NN; i++)
            tree[NN + i] = Node(IDENT_MIN, IDENT_MAX);

        for(int i = NN - 1; i > 0; i--)
            tree[i] = merge_info(tree[i * 2], tree[i * 2 + 1]);

        int q, a, b, na, nb;
        while(K--){
            scanf("%d %d %d", &q, &a, &b);
            if(q == 0){
                na = tree[NN + a].minx;
                nb = tree[NN + b].maxx;
                change_value(a, nb);
                change_value(b, na);
            }
            else{
                Node res = range_info(a, b, 1, 0, NN - 1);
                printf("%s\n", (res.minx == a && res.maxx == b) ? "YES" : "NO");
            }
        }
    }
	return 0;
}

