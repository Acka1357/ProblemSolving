#include <stdio.h>
#include <algorithm>
using namespace std;

struct Num{
	int x, idx;
	bool operator <(const Num &o)const{
		return x == o.x ? idx < o.idx : x < o.x;
	}
};

Num a[100000];
int N, tree[100001];

int get_cum(int idx){
	int sum = 0;
	for(; idx; idx -= (idx & -idx))
		sum += tree[idx];
	return sum;
}

void add_val(int idx, int val){
	for(; idx <= N; idx += (idx & -idx))
		tree[idx] += val;
}

int main()
{
	scanf("%d", &N);
	for(int i = 1; i <= N; i++){
		scanf("%d", &a[i].x);
		a[i].idx = i;
	}

	sort(a + 1, a + N + 1);

	int ans = 0;
	for(int i = 1; i < N; i++){
		ans = max(ans, i - get_cum(i));
		add_val(a[i].idx, 1);
	}
	printf("%d\n", ans);

	return 0;
}
