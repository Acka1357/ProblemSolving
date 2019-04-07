#include <stdio.h>
#include <algorithm>
#include <assert.h>
using namespace std;

struct Query{
	int l, r, m, idx;
	bool operator <(const Query &o)const{
		return m == o.m ? (l == o.l ? r < o.r : l < o.l) : m < o.m;
	}
};

int a[100001], cnt[100001], ccnt[100001], ans[100000], M, cmax;
Query q[100000];

void remove(int val){
	assert(cnt[val]);
	ccnt[cnt[val]--]--;
	ccnt[cnt[val]]++;
	if(!ccnt[cmax]) cmax--;
}

void add(int val){
	ccnt[cnt[val]++]--;
	ccnt[cnt[val]]++;
	cmax = max(cmax, cnt[val]);
}

int main()
{
	int N, Q; scanf("%d", &N);
	for(int i = 1; i <= N; i++)
		scanf("%d", &a[i]);

	M = 333;
	scanf("%d", &Q);
	for(int i = 0; i < Q; i++){
		scanf("%d %d", &q[i].l, &q[i].r);
		q[i].m = q[i].l / M, q[i].idx = i;
	}

	sort(q, q + Q);

	int l = 0, r = 0; cnt[0] = 1, ccnt[1] = 1;
	for(int i = 0; i < Q; i++){
		for(int j = q[i].l; j < l; j++) add(a[j]);
		for(int j = r + 1; j <= q[i].r; j++) add(a[j]);
		for(int j = l; j < q[i].l; j++) remove(a[j]);
		for(int j = q[i].r + 1; j <= r; j++) remove(a[j]);

		ans[q[i].idx] = cmax;
		l = q[i].l, r = q[i].r;
	}

	for(int i = 0; i < Q; i++)
		printf("%d\n", ans[i]);
	return 0;
}