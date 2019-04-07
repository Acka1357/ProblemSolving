#include <stdio.h>
#include <map>
#include <math.h>
#include <algorithm>
using namespace std;

struct Query{
    int l, r, k, qidx, bidx;
    bool operator <(const Query &A)const{
        return bidx == A.bidx ? r < A.r : bidx < A.bidx;
    }
};

map<int, int> ai;
Query q[5000];
int N, Q, NN = 1, tree[1 << 18];
int a[100000], as[100000], ia[100000], sq, ans[5000];

void add_val(int idx, int val){
	for(idx += NN; idx; idx >>= 1)
		tree[idx] += val;
}

int find_kth(int k){
	int l = 0, r = NN - 1, idx = 1;
	while(l < r){
		if(tree[idx * 2] >= k){
			r = (l + r) / 2;
			idx = idx * 2;
		}
		else{
			l = (l + r) / 2 + 1;
			k -= tree[idx * 2];
			idx = idx * 2 + 1;
		}
	}
	return ia[l];
}

int main()
{
	scanf("%d %d", &N, &Q);
	for(int i = 0; i < N; i++){
		scanf("%d", &a[i]);
		as[i] = a[i];
	}

	sort(as, as + N);

	int M = 0; 
	ai[as[0]] = M; ia[M++] = as[0];
	for(int i = 1; i < N; i++)
		if(as[i] != as[i - 1]){
			ai[as[i]] = M; ia[M++] = as[i];
		}
	for(int i = 0; i < N; i++)
		a[i] = ai[a[i]];

    sq = sqrt(M);
    for(int i = 0; i < Q; i++){
        scanf("%d %d %d", &q[i].l, &q[i].r, &q[i].k);
        q[i].l--; q[i].r--;
        q[i].qidx = i;
        q[i].bidx = q[i].l / sq;
    }

    sort(q, q + Q);

    while(NN < M) NN <<= 1;
    add_val(a[0], 1);
    int l = 0, r = 0;	// [l, r]
    for(int i = 0; i < Q; i++){
        for(int j = l; j < q[i].l; j++) add_val(a[j], -1);
        for(int j = q[i].l; j < l; j++) add_val(a[j], 1);
        for(int j = r + 1; j <= q[i].r; j++) add_val(a[j], 1);
        for(int j = q[i].r + 1; j <= r; j++) add_val(a[j], -1);
        ans[q[i].qidx] = find_kth(q[i].k);
        l = q[i].l, r = q[i].r;
    }

    for(int i = 0; i < Q; i++)
        printf("%d\n", ans[i]);

    return 0;
}
