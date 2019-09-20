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

ll cum[200005], even[200005], odd[200005];

int main()
{
	int N; scanf("%d", &N);
	for(int i = 1, x; i <= N; i++){
		cum[i] = cum[i - 1];
		scanf("%d", &x);
		cum[i] += (x < 0);
		odd[i] = odd[i - 1];
		even[i] = even[i - 1];
		if(cum[i] & 1) odd[i]++;
		else even[i]++;
	}

	ll eans = 0, oans = 0;
	for(int i = 1; i <= N; i++){
		if(cum[i] & 1){
			eans += odd[i - 1];
			oans += even[i] + 1;
			// printf("%d: odd - e:%lld o:%lld\n", i, odd[i], even[i] + 1);
		}
		else{
			eans += even[i];
			oans += odd[i];
			// printf("%d: even - e:%lld o:%lld\n", i, even[i], odd[i]);
		}
	}
	printf("%lld %lld\n", oans, eans);

	return 0;
}