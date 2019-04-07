#include <stdio.h>
#include <memory.h>
#include <algorithm>
using namespace std;

#define INF		0x3f3f3f3f3f3f3f3f

struct Memo{
	long long y, h;
	bool operator <(const Memo &o)const{
		return y < o.y;
	}
};

Memo memo[10001];
long long d[10001];

int main()
{
	int T; scanf("%d", &T);
	for(int tc = 0; tc++ < T;){
		int N; scanf("%d", &N);
		for(int i = 1; i <= N; i++)
			scanf("%*d %lld %lld\n", &memo[i].y, &memo[i].h);

		sort(memo + 1, memo + N + 1);

		memset(d, 0x3f, sizeof(d));
		d[0] = -INF;

		for(int i = 1; i <= N; i++){
			for(int j = i - 1; j >= 0; j--){
				d[j + 1] = min(d[j + 1], d[j] + memo[i].h);
				if(d[j] <= memo[i].y) d[j] = max(memo[i].y, d[j] + memo[i].h);
				else d[j] = INF;
			}
		}

		for(int i = 0; i <= N; i++)
			if(d[i] != INF){
				printf("Case #%d\n%d\n", tc, i);
				break;
			}
	}
	return 0;
}