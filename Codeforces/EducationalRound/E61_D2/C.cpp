#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <stack>
#include <utility>
using namespace std;

typedef long long ll;

int N, Q, t, l[5001], r[5001], d[5001], oc[5001], tc[5001];

int rsum(int* cum, int li, int ri){
	if(ri < li) return 0;
	return cum[ri] - cum[li - 1];
}

int main()
{
	scanf("%d %d", &N, &Q);
	for(int i = 1; i <= Q; i++){
		scanf("%d %d", &l[i], &r[i]);
		for(int j = l[i]; j <= r[i]; j++) d[j]++;
	}
	
	int sum = 0, ans = 0;
	for(int i = 1; i <= N; i++){
		if(d[i]) sum++;
		oc[i] = oc[i - 1] + (d[i] == 1);
		tc[i] = tc[i - 1] + (d[i] == 2);
	}

	for(int i = 1; i < Q; i++)
		for(int j = i + 1; j <= Q; j++){
			if(r[i] < l[j] || l[i] > r[j])
				ans = max(ans, sum - rsum(oc, l[i], r[i]) - rsum(oc, l[j], r[j]));
			else if(l[i] <= l[j] && r[j] <= r[i])
				ans = max(ans, sum - rsum(oc, l[i], l[j] - 1) - rsum(oc, r[j] + 1, r[i]) - rsum(tc, l[j], r[j]));
			else if(l[j] <= l[i] && r[i] <= r[j])
				ans = max(ans, sum - rsum(oc, l[j], l[i] - 1) - rsum(oc, r[i] + 1, r[j]) - rsum(tc, l[i], r[i]));
			else if(l[i] <= l[j])
				ans = max(ans, sum - rsum(oc, l[i], l[j] - 1) - rsum(oc, r[i] + 1, r[j]) - rsum(tc, l[j], r[i]));
			else if(l[i] >= l[j])
				ans = max(ans, sum - rsum(oc, l[j], l[i] - 1) - rsum(oc, r[j] + 1, r[i]) - rsum(tc, l[i], r[j]));
		}
	printf("%d\n", ans);

	return 0;
}
