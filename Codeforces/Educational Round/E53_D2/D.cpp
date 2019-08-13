#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <memory.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stack>
#include <utility>
using namespace std;

long long asum[200001], ex[200001];
long long N, a[200001], T, sum, ans;

long long get_cum(long long *tree, int idx){
	long long sum = 0;
	for(; idx; idx -= (idx & -idx))
		sum += tree[idx];
	return sum;
}

void add_val(long long *tree, int idx, long long val){
	for(; idx <= N; idx += (idx & -idx))
		tree[idx] += val;
}

long long take(long long *tree, long long all, int cur, int len){
	if(cur + len - 1 > N)
		return all - get_cum(tree, cur - 1) + get_cum(tree, (cur + len - 2) % N + 1);
	return get_cum(tree, cur + len - 1) - get_cum(tree, cur - 1);
}

int main()
{
	scanf("%lld %lld", &N, &T);
	for(int i = 1; i <= N; i++){
		scanf("%lld", &a[i]);
		sum += a[i];
		add_val(asum, i, a[i]);
		add_val(ex, i, 1);
	}

	long long cur = 1, suma, q, ret;
	for(int i = 1; i <= N; i++){
		if(T >= sum){
			ans += (q = T / sum) * (N - i + 1);
			T -= q * sum;
		}
		if(!T) break;

		int l = 1, r = N, m, outl = -1;
		while(l <= r){
			m = (l + r) / 2;
			suma = take(asum, sum, cur, m);
			if(suma > T){
				outl = m;
				r = m - 1;
			}
			else l = m + 1;
		}

		add_val(asum, (cur + outl - 2) % N + 1, -a[(cur + outl - 2) % N + 1]);
		add_val(ex, (cur + outl - 2) % N + 1, -1);
		sum -= a[(cur + outl - 2) % N + 1];
		ans += take(ex, N - i, cur, outl);
		T -= take(asum, sum, cur, outl);
		cur = (cur + outl - 1) % N + 1;
	}

	printf("%lld\n", ans);
	return 0;
}
