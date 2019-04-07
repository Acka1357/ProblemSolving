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

typedef long long ll;

vector<ll> sp[100001];
ll sum[100001];

int main()
{
	ll N, M; scanf("%lld %lld", &N, &M);
	for(int i = 0, s, r; i < N; i++){
		scanf("%d %d", &s, &r);
		sp[s].push_back(r);
	}
	for(int i = 1; i <= M; i++){
		ll cum = 0;
		sort(sp[i].rbegin(), sp[i].rend());
		for(int j = 0; j < sp[i].size(); j++){
			cum += sp[i][j];
			if(cum < 0) break;
			sum[j + 1] += cum;
		}
	}

	ll ans = 0;
	for(int i = 0; i <= N; i++)
		ans = max(ans, sum[i]);
	printf("%lld\n", ans);

	return 0;
}
