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

ll N, a[100001];

int main()
{
	scanf("%lld", &N);
	for(int i = 0; i < N; i++){
		scanf("%lld", &a[i]);
	}

	ll ans = -1, cur = -1, ansl = -1, curl = -1;
	for(int i = 0; i < N; i++){
		if(a[i] != cur)
			curl = 0;
		cur = a[i];
		curl++;
		if(ans <= cur){
			if(cur > ans) ansl = curl;
			else ansl = max(ansl, curl);
			ans = max(ans, cur);
		}
	}

	printf("%lld\n", ansl);

	return 0;
}
