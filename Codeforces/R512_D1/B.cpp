#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <utility>
#include <memory.h>
#include <map>
using namespace std;

int count_bit(long long x){
	int ret = 0;
	while(x){ ret += x & 1; x >>= 1; }
	return ret;
}

long long a[300002];
long long cnt[300002], cum[300002];
long long even[300002], odd[300002];

int main()
{
	int N; scanf("%d", &N);
	for(int i = 1; i <= N; i++){
		scanf("%lld", &a[i]);
		cnt[i] = count_bit(a[i]);
	}

	even[1] = 1;
	for(int i = 1; i <= N; i++){
		cum[i] = cum[i - 1] + cnt[i];
		odd[i + 1] = odd[i] + (cum[i] & 1);
		even[i + 1] = even[i] + !(cum[i] & 1);
		// printf("%d: %lld %lld\n", i, odd[i], even[i]);
	}

	long long ans = 0;
	for(int i = 1; i <= N; i++){
		if(cum[i] & 1) ans += odd[i - 1];
		else ans += even[i - 1];
	}

	// printf("%lld\n", ans);
	for(int i = 1; i <= N; i++){
		int l = i, r = i, sum = cnt[i], db = cnt[i] * 2;
		while(l > 1 && cnt[i] > cnt[l - 1] && sum + cnt[l - 1] < db) sum += cnt[--l];
		// printf("%lld: %d\n", a[i], l);
		if(l < i){
			if(cum[i] & 1) ans -= odd[i - 1] - odd[l - 1];
			else ans -= even[i - 1] - even[l - 1];
			// printf("%d [%d,%d]: %lld %lld %lld :%lld\n", a[i], l, r, cum[i], odd[i - 1] - odd[l - 1], even[i - 1] - even[l - 1], ans);
		}
		while(r < N && cnt[i] > cnt[r + 1]){
			sum += cnt[++r];
			while(l < i && sum >= db) sum -= cnt[l++];
			if(sum >= db) break;
			if(cum[r] & 1) ans -= odd[i] - odd[l - 1];
			else ans -= even[i] - even[l - 1];
			// printf("%d [%d,%d]: %lld %lld %lld :%lld\n", a[i], l, r, cum[r], odd[i] - odd[l - 1], even[i] - even[l - 1], ans);
		}
	}

	printf("%lld\n", ans);
	return 0;
}
