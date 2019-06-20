#include <stdio.h>
#include <algorithm>
#include <map>
using namespace std;

int tree[100001];

int get_cum(int idx){
	int sum = 0;
	for(; idx; idx -= (idx & -idx))
		sum += tree[idx];
	return sum;
}

void add_val(int idx, int val, int N){
	for(; idx <= N; idx += (idx & -idx))
		tree[idx] += val;
}

int a[100000], sa[100000];

int main()
{
	int N; scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%d", &a[i]);
		sa[i] = a[i];
	}
	
	sort(sa, sa + N);
	
	int cnt = 0, idx;
	map<int, int> ti;
	ti[sa[0]] = ++cnt;
	for(int i = 1; i < N; i++)
		if(sa[i] != sa[i - 1]) ti[sa[i]] = ++cnt;

	int ans = 0;
	for(int i = 0; i < N; i++){
		ans = max(ans, i - get_cum(idx = ti[a[i]]));
		add_val(idx, 1, cnt);
	}

	printf("%d\n", ans + 1);
	return 0;
}
