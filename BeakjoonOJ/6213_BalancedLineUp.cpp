#include <cstdio>
#include <algorithm>
using namespace std;

struct Node{
	Node(int minv = 0x3f3f3f, int maxv = 0): minv(minv), maxv(maxv){}
	int minv, maxv; 
};

Node tree[1 << 17];
int N, Q, NN;

Node range_q(int ql, int qr, int l = 1, int r = NN, int idx = 1){
	if(qr < l || r < ql) return Node();
	if(ql <= l && r <= qr) return tree[idx];
	Node ln = range_q(ql, qr, l, (l + r) / 2, idx * 2);
	Node rn = range_q(ql, qr, (l + r) / 2 + 1, r, idx * 2 + 1);
	return Node(min(ln.minv, rn.minv), max(ln.maxv, rn.maxv));
}

int main()
{
	scanf("%d %d", &N, &Q);
	for(NN = 1; NN < N; NN <<= 1);
	for(int i = 1; i <= N; i++){
		scanf("%d", &tree[NN + i - 1].minv);
		tree[NN + i - 1].maxv = tree[NN + i - 1].minv;
	}
	for(int i = NN - 1; i > 0; i--){
		tree[i].minv = min(tree[i * 2].minv, tree[i * 2 + 1].minv);
		tree[i].maxv = max(tree[i * 2].maxv, tree[i * 2 + 1].maxv);
	}

	for(int i = 0, ql, qr; i < Q; i++){
		scanf("%d %d", &ql, &qr);
		Node ans = range_q(ql, qr);
		printf("%d\n", ans.maxv - ans.minv);
	}

	return 0;
}
