/*
	2019 Ajou Univ. Programming Contest
	문제집 만들기 - 서브태스크3
	Acka's cpp solution
	Time Complexity: O((N + Q) * logN)
*/

#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

struct Node{ 
	int vmin, vmax; 
	Node(int vmin = 100001, int vmax = 0): vmin(vmin), vmax(vmax){}
};

Node merge(Node l, Node r){
	return {min(l.vmin, r.vmin), max(l.vmax, r.vmax)};
}

int NN;
Node tree[1 << 18];
set<int> pre[100001];

Node range_q(int ql, int qr, int l = 1, int r = NN, int idx = 1){
	if(qr < l || r < ql) return Node();
	if(ql <= l && r <= qr) return tree[idx];
	return merge(range_q(ql, qr, l, (l + r) / 2, idx * 2),
				 range_q(ql, qr, (l + r) / 2 + 1, r, idx * 2 + 1));
}

void upd(int idx){
	for(idx = (NN + idx - 1) / 2; idx; idx >>= 1)
		tree[idx] = merge(tree[idx * 2], tree[idx * 2 + 1]);
}

int main()
{
	int N, M, Q; scanf("%d %d %d", &N, &M, &Q);
	for(int i = 0, u, v; i < M; i++){
		scanf("%d %d", &u, &v);
		pre[u].insert(v);
	}

	for(NN = 1; NN < N; NN <<= 1);
	for(int i = 1; i <= N; i++){
		pre[i].insert(i);
		tree[NN + i - 1] = Node(*pre[i].begin(), *pre[i].rbegin());
	}
	for(int i = NN - 1; i > 0; i--)
		tree[i] = merge(tree[i * 2], tree[i * 2 + 1]);

	while(Q--){
		int w, x, y; scanf("%d %d %d", &w, &x, &y);
		if(w == 1){
			Node res = range_q(x, y);
			printf("%s\n", (x == res.vmin && y == res.vmax) ? "YES" : "NO");
		}
		else{
			if(w == 2) pre[x].erase(y);
			else pre[x].insert(y);
			tree[NN + x - 1] = Node(*pre[x].begin(), *pre[x].rbegin());
			upd(x);
		}
	}

	return 0;
}
