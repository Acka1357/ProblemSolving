//
// Created by Acka on 2017. 4. 27..
//

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

struct Node{
    int hat, cnt;
    Node(){}
    Node(int h, int c):hat(h), cnt(c){}
    Node merge(Node A){
        if(hat == A.hat)
            return Node(hat, cnt + A.cnt);
        else if(cnt > A.cnt)
            return Node(hat, cnt - A.cnt);
        else
            return Node(A.hat, A.cnt - cnt);
    }
};

int NN;
Node tree[1 << 20];
vector<int> hat[10001];

Node get_max(int ql, int qr, int idx = 1, int l = 1, int r = NN){
    if(r < ql || qr < l) return Node(0, 0);
    if(ql <= l && r <= qr) return tree[idx];
    return get_max(ql, qr, idx * 2, l, (l + r) / 2)
            .merge(get_max(ql, qr, idx * 2 + 1, (l + r) / 2 + 1, r));
}

int main()
{
    int N, C; scanf("%d %d", &N, &C);
    for(NN = 1; NN < N; NN <<= 1);
    for(int i = 0, h; i < N; i++) {
        scanf("%d", &h);
        hat[h].push_back(i + 1);
        tree[NN + i] = Node(h, 1);
    }

    for(int i = NN - 1; i > 0; i--)
        tree[i] = tree[i * 2].merge(tree[i * 2 + 1]);

    for(int i = 1; i <= C; i++)
        sort(hat[i].begin(), hat[i].end());

    int M, l, r; for(scanf("%d", &M); M--;){
        scanf("%d %d", &l, &r);
        Node ans = get_max(l, r);
        int ans_cnt = upper_bound(hat[ans.hat].begin(), hat[ans.hat].end(), r)
                      - lower_bound(hat[ans.hat].begin(), hat[ans.hat].end(), l);
        if(ans.cnt && (r - l + 1) / 2 < ans_cnt)
            printf("yes %d\n", ans.hat);
        else printf("no\n");
    }

    return 0;
}
