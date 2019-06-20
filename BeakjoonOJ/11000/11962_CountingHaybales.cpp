#include <stdio.h>
#include <algorithm>
using namespace std;

struct Node{ 
	long long sum, min, add; 
	Node(){} Node(long long s, long long m):sum(s), min(m){}
};

Node tree[1 << 19];
int NN;

long long range_min(int ql, int qr, int idx = 1, int l = 1, int r = NN, long long cum = 0){
	if(r < ql || qr < l) return 1e18;
	if(ql <= l && r <= qr) return tree[idx].min + tree[idx].add + cum;
	return min(range_min(ql, qr, idx * 2, l, (l + r) / 2, cum + tree[idx].add), 
			range_min(ql, qr, idx * 2 + 1, (l + r) / 2 + 1, r, cum + tree[idx].add));
}

long long range_sum(int ql, int qr, int idx = 1, int l = 1, int r = NN, long long cum = 0){
	if(r < ql || qr < l) return 0;
	if(ql <= l && r <= qr) return tree[idx].sum + (r - l + 1) * (tree[idx].add + cum);
	return range_sum(ql, qr, idx * 2, l, (l + r) / 2, cum + tree[idx].add) 
			+ range_sum(ql, qr, idx * 2 + 1, (l + r) / 2 + 1, r, cum + tree[idx].add);
}

Node range_add(int ql, int qr, long long val, int idx = 1, int l = 1, int r = NN){
	if((r < ql || qr < l) || (ql <= l && r <= qr)){ 
		if(ql <= l && r <= qr) tree[idx].add += val; 
		return Node(tree[idx].sum + (r - l + 1) * tree[idx].add, tree[idx].min + tree[idx].add); 
	}

	Node left = range_add(ql, qr, val, idx * 2, l, (l + r) / 2);
	Node right = range_add(ql, qr, val, idx * 2 + 1, (l + r) / 2 + 1, r);
	tree[idx].sum = left.sum + right.sum;
	tree[idx].min = min(left.min, right.min);
	return Node(tree[idx].sum + (r - l + 1) * tree[idx].add, tree[idx].min + tree[idx].add);
}

int main()
{
	int N, Q, a, b, c; scanf("%d %d", &N, &Q);
	for(NN = 1; NN < N; NN <<= 1);
	for(int i = 1; i <= N; i++){
		scanf("%lld", &tree[NN + i - 1].sum);
		tree[NN + i - 1].min = tree[NN + i - 1].sum;
	}
	for(int i = N + 1; i <= NN; i++)
		tree[NN + i - 1].min = 1e18;
	for(int i = NN - 1; i; i--){
		tree[i].sum = tree[i * 2].sum + tree[i * 2 + 1].sum;
		tree[i].min = min(tree[i * 2].min, tree[i * 2 + 1].min);
	}

	char cmd;
	while(Q--){
		scanf(" %c %d %d", &cmd, &a, &b);
		if(cmd == 'M') printf("%lld\n", range_min(a, b));
		else if(cmd == 'S') printf("%lld\n", range_sum(a, b));
		else{
			scanf("%d", &c);
			range_add(a, b, c);
		}
	}
	return 0;
}