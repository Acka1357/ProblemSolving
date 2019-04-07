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

long long N, K, h[200001], cnt[200001];

int main()
{
	scanf("%lld %lld", &N, &K);
	for(int i = 1; i <= N; i++){
		scanf("%lld", &h[i]);
		cnt[h[i]]++;
	}

	long long ans = 0, cur = 0, cum = 0, same = 0;
	for(int i = 200000; i > 0; i--){
		if((same += cnt[i]) == N) break;
		cum += cnt[i];
		cur += cum;
		if(cur > K){
			ans++;
			cur = cum;
		}
	}
	printf("%lld\n", ans + (cur != 0));
	return 0;
}
