#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <utility>
#include <functional>
#include <cstdlib>
#include <cmath>
#include <string>
#include <set>
#include <map>
using namespace std;

typedef long long ll;

// bool win[101];

int main()
{
	// int K; scanf("%d", &K);
	// for(int i = 0; i <= 30; i++){
	// 	printf("%c", win[i] ? 'W' : 'L');
	// 	if(!win[i]){
	// 		win[i + 1] = win[i + 2] = win[i + K] = true;
	// 	}
	// }
	// printf("\n");

	int T; for(scanf("%d", &T); T--;){
		ll N, K; scanf("%lld %lld", &N, &K);
		if(K % 3 == 0){
			ll r = N % (K + 1);
			if(r == K) printf("Alice\n");
			else printf("%s\n", (r % 3) ? "Alice" : "Bob");
		}
		else printf("%s\n", (N % 3) ? "Alice" : "Bob");
	}

	return 0;
}

// 3
// LWWWLWWWLWWWLWWWLWWWLWWWLWWWLWW
// 4
// LWWLWWLWWLWWLWWLWWLWWLWWLWWLWWL
// 5
// LWWLWWLWWLWWLWWLWWLWWLWWLWWLWWL
// 6
// LWWLWWWLWWLWWWLWWLWWWLWWLWWWLWW
// 7
// LWWLWWLWWLWWLWWLWWLWWLWWLWWLWWL
// 8
// LWWLWWLWWLWWLWWLWWLWWLWWLWWLWWL
// 9
// LWWLWWLWWWLWWLWWLWWWLWWLWWLWWWL
// 10
// LWWLWWLWWLWWLWWLWWLWWLWWLWWLWWL
// 11
// LWWLWWLWWLWWLWWLWWLWWLWWLWWLWWL
// 12
// LWWLWWLWWLWWWLWWLWWLWWLWWWLWWLW
// 13
// LWWLWWLWWLWWLWWLWWLWWLWWLWWLWWL
// 14
// LWWLWWLWWLWWLWWLWWLWWLWWLWWLWWL
