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

long long N, X, Y, D; 

long long need(int from, int to){
	long long g = (from < to ? (to - from) : (from - to));
	long long l = 0, r = g, m, ans;
	while(l <= r){
		m = (l + r) / 2;
		if(g <= m * D){
			ans = m;
			r = m - 1;
		}
		else l = m + 1;
	}
	return ans;
}

bool exact(int from, int to){
	int g = (from < to ? (to - from) : (from - to));
	return (g % D) == 0;
}

int main()
{
	int tc; for(scanf("%d", &tc); tc--;){
		scanf("%lld %lld %lld %lld", &N, &X, &Y, &D);
		if(X == Y) printf("%d\n", 0);
		else if(exact(X, Y)) printf("%d\n", need(X, Y));
		else{
			long long ans1 = -1, ans2 = -1;
			if(exact(1, Y)) ans1 = need(X, 1) + need(1, Y);
			if(exact(N, Y)) ans2 = need(X, N) + need(N, Y);
			if(ans1 >= 0 && ans2 >= 0) printf("%lld\n", min(ans1, ans2));
			else if(ans1 >= 0) printf("%lld\n", ans1);
			else if(ans2 >= 0) printf("%lld\n", ans2);
			else printf("-1\n");
		}
	}
	return 0;
}
